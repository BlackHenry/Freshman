#include <iostream>

using namespace std;

int GCD(int a, int b){
    while(a%=b^=a^=b^=a)
    ;
    return b;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << a * b / GCD(a, b);
    return 0;
}
