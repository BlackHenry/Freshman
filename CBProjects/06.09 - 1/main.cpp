#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool prime(int a)
{
    if(a == 1)
        return 0;
    for(int i = 2; i*i <= a; i++)
    {
        if(a % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    for(int i = 1; i < 101; i++)
    {
        if(prime(i))
            cout << i << endl;
    }

    return 0;
}
