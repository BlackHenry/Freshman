#include <iostream>
#include <cmath>

using namespace std;

long double n,w,h;

bool F(long double a){
    return ceil(n/a)<=floor(a*h/w);
}

int main()
{
    cin >> w >> h >> n;
    if(w > h)
        swap(w, h);
    long long int l = ceil(sqrt(w*h*n)/h);
    long long int r = n;
    while(r - l > 1){
        long long int k = (l + r)/2;
        if(F(k)){
            r = k;
        }
        else{
            l = k;
        }
    }
    for(int i = min(100ll, l); i >= 0; i--){
        if(F(l - i)){
            cout << (l - i) * h;
            return 0;
        }
    }
    if(F(r)){
        cout << r * h;
        return 0;
    }
}
