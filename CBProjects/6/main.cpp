#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long double x = 5;
    for(int  i = 0; i < 10000; i++){
        x = sqrt(5 + x);
        cout << x << endl;
    }
    return 0;
}
