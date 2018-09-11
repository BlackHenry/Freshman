#include <iostream>
#include <map>

using namespace std;

int n;

int main()
{
    map<int, int> mp;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        mp[a]++;
    }
    for(auto it: mp){
        for(int i = 0; i < it.second; i++){
            cout << it.first << " ";
        }
    }
    return 0;
}
