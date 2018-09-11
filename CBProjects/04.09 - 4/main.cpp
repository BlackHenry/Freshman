#include <iostream>
#define ll long long

using namespace std;

int main()
{
    ll a = 1, b = 1, n;
    cin >> n;
    for(int i = 1; i < n; i++){
        a += b;
        a ^= b ^= a ^= b;
    }
    cout << a << endl;
    return 0;
}
