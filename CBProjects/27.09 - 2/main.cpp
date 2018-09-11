#include <iostream>

using namespace std;

int n;

int S(int n){
    int s = 0;
    while(n){
        s += n%10;
        n /= 10;
    }
    return s;
}

int main()
{
    cin >> n;
    for(int i = 10; i < 100; i++){
        if(n - S(i) < 10 && n - S(i) >= 0){
            cout << i << n - S(i) << endl;
        }
    }
    return 0;
}
