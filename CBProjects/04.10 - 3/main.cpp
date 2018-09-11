#include <iostream>
#include <cmath>

using namespace std;

int n, arr[1000];

bool Rnd(int seed){
    long double a = sin(tgamma(seed + 1));
    return a >= 0.5;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        arr[i] = int(Rnd(i + 1));
    }
    int a = 0, m = -1;
    for(int i = 0; i < n; i++){
        if(!arr[i]){
            a++;
        }
        else{
            m = max(a, m);
            a = 0;
        }
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl << m << endl;
    return 0;
}
