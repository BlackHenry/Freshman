#include <iostream>

using namespace std;

long long C(long long n, long long k){
    if(k == 1 || k == n - 1)
        return n;
    return C(n - 1, k) + C(n - 1, k - 1);
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << C(n, k) << endl;
    return 0;
}
