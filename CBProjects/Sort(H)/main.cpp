#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long int> vrr;
long long int n;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        vrr.push_back(a);
    }
    sort(vrr.begin(), vrr.end());
    vrr.push_back(2e18);
    long long int prr = 0;
    for(int i = 0; i < vrr.size(); i++){
        if(vrr[i] > prr + 1){
            cout << prr + 1<< endl;
            return 0;
        }
        prr += vrr[i];
    }
    return 0;
}
