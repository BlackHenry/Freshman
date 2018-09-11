#include <iostream>

using namespace std;

int count_z(string s){
    int k = 0;
    for(auto it: s){
        if(it == '0')
            k++;
    }
    return k;
}

int main()
{
    int n, k1 = 0;
    cin >> n;
    for(int i = 1; i < n; i++){
        k1 += count_z(to_string(i));
    }
    cout << k1 << endl;
    return 0;
}
