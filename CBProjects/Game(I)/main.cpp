#include <iostream>
#include <vector>

using namespace std;

vector<long long int> vrr;

int main()
{
    long long int s = 0, m, k = 0, n;
    cin >> n;
    for(long long int i = 0; i < n; i++){
        long long int a;
        cin >> a;
        vrr.push_back(a);
        s ^= a;
    }
    if(!s){
        cout << 0 << endl;
        return 0;
    }
    for(long long int i = 2; i <= s * 2; i *= 2){
        if(s%i){
            m = i/2;
        }
    }
    for(long long int i = 0; i < vrr.size(); i++){
        //cout << m << " " << vrr[i] << " " << long long int(vrr[i]^m) << endl;
        if(vrr[i] >= m && (int(vrr[i]^m) < vrr[i]))
            k++;
    }
    cout << k << endl;
    return 0;
}
