#include <iostream>
#include <cmath>

using namespace std;

long long n, d;

int main()
{
    cin >> d;
    for(int i = 0; i < d; i++){
        int k = 0, a = 2;
        cin >> n;
        while(n){
            if(n%a){
                cout << k << " ";
            }
            n -= (n%a);
            k++;
            a*=2;
        }
        cout << endl;
    }
    return 0;
}
