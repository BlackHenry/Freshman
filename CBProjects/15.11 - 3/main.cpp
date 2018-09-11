#include <iostream>
#include <vector>
#include <map>

using namespace std;

int used[1000], n;
vector<pair<int, int> > dominos, seq, max_seq;

int comp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first)
        return a.first;
    if(a.first == b.second)
        return a.first;
    if(a.second == b.first)
        return a.second;
    if(a.second == b.second)
        return a.second;
    return 0;
}

bool can_place(int k){
    if(!k){
        max_seq = seq;
        return 1;
    }
    for(int i = 0; i < n; i++){
        if(!used[i]){
            if(seq.size() == 0){
                used[i] = 1;
                seq.push_back(dominos[i]);
                can_place(k - 1);
                used[i] = 0;
                seq.pop_back();
                continue;
            }
            if(comp(seq.back(), dominos[i])){
                if(comp(seq.back(), dominos[i]) == comp(seq[seq.size() - 2], seq.back())){
                    continue;
                }
                used[i] = 1;
                seq.push_back(dominos[i]);
                can_place(k - 1);
                used[i] = 0;
                seq.pop_back();
            }
        }
    }
    if(seq.size() > max_seq.size()){
        max_seq = seq;
    }
    return 0;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        dominos.push_back(make_pair(a, b));
    }
    can_place(n);
    cout << endl;
    for(auto it: max_seq){
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}
