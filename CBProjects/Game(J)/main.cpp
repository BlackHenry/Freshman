#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k, s1, s2;
vector<int> vrr, num(33);

void printV(vector<int> vr){
    for(int i = 0; i < vr.size(); i++){
        cout << vr[i];
    }
    cout << endl;
}

vector<int> Move(){
    int u = 0;
    for(int i = 0; i < 33; i++){
        if(num[i]){
            int s = num[i];
            int q = (s + u) % (k + 1);
            if(q <= u){

            }
        }
    }
}

vector<int> toBinary(int n)
{
    vector<int> vr;
    int a;
    while(n!=0) {a=(n%2==0 ?0:1); n/=2; vr.push_back(a);}
    while(vr.size() < 33){
        vr.push_back(0);
    }
    reverse(vr.begin(), vr.end());
    return vr;
}

vector<int> Sum(vector<int> a, vector<int> b){
    vector<int> s;
    for(int i = 0; i < a.size(); i++){
        s.push_back((a[i] + b[i])%(k + 1));
    }
    return s;
}

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        vrr.push_back(a);
        num = Sum(toBinary(a), num);
    }
    bool t = true;
    for(int i = 0; i < num.size(); i++){
        if(num[i]){
            t = 0;
            break;
        }
    }
    printV(num);
    if(t){
        cout << 0 << endl;
        return 0;
    }
    return 0;
}
