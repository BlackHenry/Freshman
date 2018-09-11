#include <iostream>

using namespace std;

int n0, m, k, dpp[300][300], brr[10000];
const int D = 600;
vector<int> vrr;
vector<vector<int> > grr, arr;

int mex (const vector<int> & a) {
	static bool used[D+1] = { 0 };
	int c = (int) a.size();

	for (int i=0; i<c; ++i)
		if (a[i] <= D)
			used[a[i]] = true;

	int result;
	for (int i=0; ; ++i)
		if (!used[i]) {
			result = i;
            break;
		}

	for (int i=0; i<c; ++i)
		if (a[i] <= D)
			used[a[i]] = false;

	return result;
}

int ShGr(int n, int m){
    if(dpp[n][m] != -1){
        return dpp[n][m];
    }
    if(!arr[grr[n][m]]){
        dpp[n][m] = 0;
        return 0;
    }
    vector<int> vrr;
    for(int i = 1; i < n; i++){
        vrr.push_back(ShGr(n - i, m)^ShGr(i, m));
    }
    for(int i = 1; i < m; i++){
        vrr.push_back(ShGr(n, m - i)^ShGr(n, i));
    }
    int a = mex(vrr);
    dpp[n][m] = a;
    dpp[m][n] = a;
    return a;
}

void find_paths(int a, int k, int n){
    if(!arr[a].size()){
        grr[n].push_back(k);
    }
    for(int i = 0; i < arr[a].size(); i++){
        find_paths(arr[a][i], k + 1, n);
    }
}

int main()
{
    cin >> n0 >> m >> k;
    arr.resize(n0);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        brr[a] = 1;
    }
    for(int i = 0; i < k; i++){
        int a;
        cin >> a;
        vrr.push_back(a);
    }
    grr.resize(k);
    for(int i = 0; i < k; i++){
        find_paths(vrr[i], 0, vrr[i]);
    }
    return 0;
}
