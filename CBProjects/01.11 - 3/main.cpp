#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n, m;
vector<int> vr;

bool f(int n, int k){
    if(k == 1){
        if(sqrt(n) == floor(sqrt(n))){
            vr.push_back(n);
            return 1;
        }
        return 0;
    }
    for(int i = 1; i*i < n; i++){
        if(f(n - i*i, k - 1)){
            vr.push_back(i*i);
            return 1;
        }
    }
    return 0;
}

int main()
{
    cin >> n >> m;
    if(f(n, m)){
        for(int i = 0; i < vr.size(); i++){
            cout << vr[i] << " ";
        }
    }
    return 0;
}
