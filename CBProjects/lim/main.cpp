#include <cmath>
#include <iostream>

using namespace std;



long double p(long double x){
    long double s = 0;
    for(int i = 0; i < x; i++)
        s += cos(x)/pow(2, x);
    return s;
}

int main()
{
    for(int i = 0; i < 100; i++){
        cout << p(i) << endl;
    }
    return 0;
}
