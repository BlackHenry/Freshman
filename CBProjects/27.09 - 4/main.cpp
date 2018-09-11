#include <iostream>
#include <map>

using namespace std;

int n;

int main()
{
    map<int, int> mp;
    cin >> n;
    int a = n;
    for(int i = 2; i*i <= n; i++){
        while(!(a % i)){
            a /= i;
            mp[i]++;
        }
    }
    for(auto it: mp){
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}
