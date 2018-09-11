#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;

int n, arr[2000][2];

long long D(int x1, int y1, int x2, int y2){
    return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}

bool on_line(int x1, int y1, int x2, int y2, int x3, int y3){
    long int a1 = x1 - x2;
    long int a2 = x2 - x3;
    long int b1 = y1 - y2;
    long int b2 = y2 - y3;
    return a1*b2 - a2*b1;
}

int C(int n){
    return n*(n-1)/2;
}

int main()
{
    long int k = 0;
    unordered_map<int, int> mp, mp1;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;

            long long a = D(arr[i][0], arr[i][1], arr[j][0], arr[j][1]);
            if(mp[a]){
                mp1[a]++;
            }
            mp[a]++;
        }
        for(auto it: mp1){
            cout << it.first << " " << it.second << endl;
            k += C(it.second + 1);
        }
        mp.clear();
        mp1.clear();
    }
    cout << k;
    return 0;
}
