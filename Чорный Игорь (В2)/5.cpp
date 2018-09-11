#include <iostream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;
vector<pair<int, int> > subs;
vector<bool> used;

char s_input[1000], s_mask[1000];

vector<int> locate(pair<int, int> p){
    vector<int> res;
    for(int i = 0; i < strlen(s_input) - (p.second - p.first); i++){
        int j = 0;
        for(j = p.first; j < p.second; j++){
            if(s_input[i + j - p.first] != s_mask[j]){
                break;
            }
        }
        if(j == p.second){
            res.push_back(i);
        }
    }
    return res;
}

bool is_symb(char c){
    return (c!='?'&&c!='*');
}

bool comp(int l, int r){
    int k_star = 0, k_quest = 0;
    for(int i = l; i < r; i++){
        if(s_mask[i] == '*')
            k_star++;
        else
            k_quest++;
    }
    return ((k_star || k_quest == r - l) && k_quest <= r - l);
}

bool is_mask(int l, int r){
    pair<int, int> str = make_pair(-1, -1);
    int str_num = -1;
    for(int i = 0; i < used.size(); i++){
        if(!used[i]){
            if(subs[i].first >= l && subs[i].second <= r){
                str = subs[i];
                used[i] = 1;
                str_num = i;
            }
            break;
        }
    }
    if(str_num == -1){
        return comp(l, r);
    }
    vector<int> locs = locate(str);
    for(int i = 0; i < locs.size(); i++){
        if(is_mask(l, locs[i]) && is_mask(locs[i] + (str.second - str.first), r)){
            return 1;
        }
    }
    used[str_num] = 0;
    return 0;
}

int main()
{
    cin >> s_input >> s_mask;
    for(int i = 0; i < strlen(s_mask) - 1; i++){
        int beg = i, end_ = i;
        while(is_symb(s_mask[i + 1]) && i < strlen(s_mask) - 1){
            end_++;
            i++;
        }
        if(beg)
            beg++;
        if(beg == 0 && !(is_symb(s_input[0])))
            beg++;
        subs.push_back(make_pair(beg, end_));
    }
    used.resize(subs.size());
    for(int i = 0; i < used.size(); i++){
        used[i] = 0;
    }
    if(is_mask(0, strlen(s_input))){
        cout << "Mask is correct!\n";
    }
    else{
        cout << "Incorrect mask!\n";
    }
    return 0;
}
