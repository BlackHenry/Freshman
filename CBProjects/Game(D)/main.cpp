#include <iostream>
#include <vector>

using namespace std;

int n0, m0, s, dpp[300][300];
const int D = 600;

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
    if((n == 1 && m <= s) || (m == 1 && n <= s)){
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

int main()
{
    cin >> n0 >> m0 >> s;
    fill(dpp[0], dpp [299] + 300, -1);
    int a = ShGr(n0, m0);
    if(a){
        cout << "1\n";
        return 0;
    }

    cout << "2\n";
    //cout << ShGr(n0, m0) << endl;
    /*for(int i = 1; i < n0 + 1; i++){
        for(int j = 1; j < m0 + 1; j++){
            cout << dpp[i][j] << " ";
        }
        cout << endl;
    }*/
    return 0;
}
