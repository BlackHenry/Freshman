#include <iostream>
#include <vector>

using namespace std;

int n;
bool arr[100000];
vector<int> vr;

bool prime(int a){
    for(int i = 2; i <= a/i; i++){
        if(!(a%i))
            return 0;
    }
    return 1;
}

int main()
{
    cin >> n;
    for(int i = 2; i < n; i++){
        if(prime(i)){
            arr[i] = 1;
            vr.push_back(i);
        }
    }
    for(auto it: vr){
        if(arr[n - it]){
            cout << it << " " << n - it << endl;
            return 0;
        }
    }
    return 0;
}
