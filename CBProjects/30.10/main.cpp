#include <iostream>

using namespace std;

union A{
    int i;
    double d;
    char c[4];
} a;

enum {two = 2, two = two};

int main()
{
    a.d = 11123.2422222223;
    a.i = 1234567890;
    //a.c[0] = '1';
    //a.c[3] = '2';
    cout << a.i << " " << a.d << " " << sizeof(double) << endl;
    return 0;
}
