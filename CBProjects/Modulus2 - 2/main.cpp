#include <iostream>
#include <cmath>

using namespace std;

long double pow(long double x, int n){
    cout << "!\n";
    long double temp;
    if(n > 0)
        temp = x;
    else
        temp = 1.0/x;
    int i, k = abs(n);
    if(k == 1){
        return temp;
    }
    if(!k){
        return 1;
    }
    for(i = 2; i <= k; i *= 2){
        temp = temp*temp;
    }
    i = i/2;
    if(n > 0)
        temp = temp * pow(x, n - i);
    else
        temp = temp * pow(x, n + i);
    return temp;
}

int main()
{
    long double x;
    int n;
    cin >> x >> n;
    cout << pow(x, n) << endl;
    return 0;
}
