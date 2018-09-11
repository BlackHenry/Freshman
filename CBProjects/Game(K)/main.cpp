#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k0, dpp[300][300];
vector<int> vrr, p;

void printV(vector<int> vr){
    for(int i = 0; i < vr.size(); i++){
        cout << vr[i] << endl;
    }
    cout << endl;
}

int dp(int l, int k){
    int s = 0;
    if(l == n){
        return 0;
    }
    if(l == n - 1)
        return vrr[l];
    if(dpp[l][k])
        return dpp[l][k];
    for(int i = 1; i <= min(k, n - l); i++){
        s = max(s, p[l] - dp(l + i, i));
    }
    //int a = max(vrr[l] + p[r] - p[l] - dp(l + 1, r), vrr[r] + p[r - 1] - p[l - 1] - dp(l, r - 1));
    dpp[l][k] = s;
    return s;
}

int main()
{
    int s = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        vrr.push_back(a);
    }
    cin >> k0;
    for(int i = n - 1; i >= 0; i--){
        s += vrr[i];
        p.push_back(s);
    }
    reverse(p.begin(), p.end());
    cout << dp(0, k0) << endl;
    return 0;
}
