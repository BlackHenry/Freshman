#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;
    int a1 = a / 1000, a2 = (a % 1000) / 100, a3 = (a % 100) / 10, a4 = a % 10;
    if(a1 + a2 == a3 + a4)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
