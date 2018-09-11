#include <iostream>

using namespace std;

int n;

bool prime(int a){
    for(int i = 2; i <= a/i; i++){
        if(!a%i)
            return 0;
    }
    return 1;
}

int main()
{
    cin >> n;
    int i = n - n%6 + 6;
    for(; i < 2*n; i+=6){
        if(prime(i-1)&&prime(i+1)){
            cout << i-1 << " " << i+1 << endl;
        }
    }
    return 0;
}
