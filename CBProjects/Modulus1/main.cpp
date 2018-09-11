#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> input_arr;
unordered_map<int, vector<int> > index_map;
int n;

int main()
{
    cin >> n;
    input_arr.resize(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        index_map[a].push_back(i);
    }
    int max_size = 0, max_key = 0;
    for(auto it: index_map){
        if(max_size < it.second.size()){
            max_size = it.second.size();
            max_key = it.first;
        }
    }
    vector<int> result = index_map[max_key];
    cout << result.size() << endl;
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}
