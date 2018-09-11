#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, k = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        double a;
        cin >> a;
        k += a<30.0;
    }
    cout << ceil(k * 2.0 / 9.0) << " " << k << endl;
    return 0;
}
