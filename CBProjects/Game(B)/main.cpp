#include <iostream>
#include <cmath>

using namespace std;

long long int n;

int main()
{
    cin >> n;
    bool t = 1;
    while(n > 1){
        if(t)
            n = ceil(n / 9.0);
        else
            n = floor(n / 2.0);
        t = !t;
    }
    if(!t){
        cout << "Stan wins.\n";
    }
    else{
        cout << "Ollie wins.\n";
    }
    return 0;
}
