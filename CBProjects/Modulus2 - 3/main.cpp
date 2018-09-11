#include <iostream>
#include <vector>

using namespace std;
vector<int> B;
int n;

int GCD(int a, int b){
    while(a){
        a%=b^=a^=b^=a;
    }
    return b;
}

int main()
{
    int a, b;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(i){
            B.push_back(GCD(a, b));
        }
        b = a;
    }
    for(int i = 0; i < B.size(); i++){
        cout << B[i] << " ";
    }
    cout << endl;
    return 0;
}
