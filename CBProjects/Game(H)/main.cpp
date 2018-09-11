#include <iostream>
#include <vector>

using namespace std;

int n, dpp[3000][3000];
vector<int> vrr, p;

int dp(int l, int r){
    if(l == r)
        return vrr[l];
    if(dpp[l][r])
        return dpp[l][r];
    int a = max(vrr[l] + p[r] - p[l] - dp(l + 1, r), vrr[r] + p[r - 1] - p[l - 1] - dp(l, r - 1));
    dpp[l][r] = a;
    return a;
}

int main()
{
    int s = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        vrr.push_back(a);
        s += a;
        p.push_back(s);
    }
    cout << dp(0, n - 1) << endl;
    return 0;
}
