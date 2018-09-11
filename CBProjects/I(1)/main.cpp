#include <iostream>
#include <cmath>

using namespace std;

long double n,w,h;

bool F(long double a){
    return ceil(n/(floor(a/h)))<=floor(a/w);
}

int main()
{
    cin >> w >> h >> n;
    if(w < h)
        swap(w, h);
    long long int l = ceil(sqrt(w*h*n));
    long long int r = n * h;
    while(r - l > 1){
        long long int k = (l + r)/2;
        if(F(k)){
            r = k;
        }
        else{
            l = k;
        }
    }
    if(F(l))
        cout << l <<endl;
    else
        cout << r << endl;
    return 0;
}
