#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    long double d;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> d;
        cout << fixed << setprecision(10) << d/6.0 << endl;
    }
    return 0;
}
