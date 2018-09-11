#include <iostream>
#include <vector>

using namespace std;

int n, arr[2000];
vector<vector<int> > vrr;

int func(int k, int t){
    //cout << k << endl;
    vector<int> vr = vrr[k];
    int k0 = 0, k1 = 0, k2 = 0;
    if(vr.size()){
        for(int i = 0; i < vr.size(); i++){
            if(func(vr[i], !t) == -1){
                k2++;
            }
            if(func(vr[i], !t) == 0){
                k0++;
            }
            if(func(vr[i], !t) == 1){
                k1++;
            }
        }
        if(t){
            if(k1)
                return 1;
            if(k0)
                return 0;
            return -1;
        }
        if(k2)
            return -1;
        if(k0)
            return 0;
        return 1;
    }
    return arr[k];
}

int main()
{
    cin >> n;
    n--;
    vrr.resize(n);
    for(int i = 0; i < n; i++){
        vector<int> vr;
        vrr.push_back(vr);
    }
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        if(s == "N"){
            int a;
            cin >> a;
            a--;
            vrr[a].push_back(i);
            arr[i] = -1;
        }
        else{
            int a;
            cin >> a;
            a--;
            vrr[a].push_back(i);
            cin >> a;
            arr[i] = a;
        }
    }
    int a = func(0, 1);
    if(a == 1){
        cout << "+" << a << endl;
        return 0;
    }
    cout << a << endl;
    return 0;
}
