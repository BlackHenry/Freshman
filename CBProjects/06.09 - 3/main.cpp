#include <iostream>
#include <set>
#include <cmath>

using namespace std;

long long int arr[1000];

int main()
{
    int n;
    set<int> srr;
    set<int>::iterator it;
    for(int i = 0; i < 1000; i++){
        arr[i] = abs(floor(sin((tgamma(i + 5)) * 48686) * 10000));
        cout << arr[i] << " ";
    }
    cin >> n;
    for(int i = 0; i <= n; i++){
        srr.insert(arr[i]);
    }
    cout << srr.size() << endl;
    for(it = srr.begin(); it != srr.end(); it++){
        cout << *it << " ";
    }
    return 0;
}
