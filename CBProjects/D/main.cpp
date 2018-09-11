#include <iostream>
#include <cmath>

using namespace std;

long long n;

bool prime(long long n){
    for(int i = 2; i <= sqrt(n); i+=2){
        if(n%i == 0)
            return false;
        if(i==2)i--;
    }
    return true;
}

int main()
{
    bool t = 1;
    cin >> n;
    long long n0 = n;
    for(long long i = 2; i*i <= n0; i++){
        while(!(n%i)){
            if(t){
                cout << i;
                t = 0;
            }
            else{
                cout << "*" << i;
            }
            n/=i;
        }
        if(n == 1){
            break;
        }

    }
    if(n-1){
        if(!t){
            cout << "*";
        }
        cout << n;
    }
    cout << endl;
    return 0;
}
