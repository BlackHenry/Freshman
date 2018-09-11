#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vrr;
int n;

int main()
{
    int a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        vrr.push_back(a);
    }
    sort(vrr.begin(), vrr.end());
    cin >> a;
    int l = 0, r = vrr.size() - 1, res = 0;
    while(l < r - 1){
        int m = (l + r) / 2;
        if(vrr[m] > a){
            r = m;
        }
        if(vrr[m] < a){
            l = m;
        }
        if(vrr[m] == a){
            res = m;
            break;
        }
    }
    l++;
    vector<int>::iterator it = vrr.begin();
    advance(it, l);
    vrr.insert(it, a);
    for(int i = 0; i < vrr.size(); i++){
        cout << vrr[i] << " ";
    }
    cout << endl;
    return 0;
}
