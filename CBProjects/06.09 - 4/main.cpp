#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, s = 0;
    cin >> a;
    while(a){
        s += a % 10;
        a /= 10;
    }
    if(s % 2){
        cout << "Sum is odd";
    }
    else{
        cout << "Sum is even";
    }
    return 0;
}
