#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 10000;

struct Stack{
    int size = 0;
    int data[SIZE];
}s;

int F(int m, int n){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            s.data[i + j] = !(i*j) ? i + j + 1: s.data[i - 1 + s.data[m + n - 1]];
        }
    }
    return s.data[n + m];
}

int F_rec(int m, int n){
    if(!(m*n)){
        return m + n + 1;
    }
    return F_rec(m - 1, F_rec(m, n - 1));
}

int main()
{
    int n, m;
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << i << " " << F(i, j) << " " << F_rec(i, j) << endl;
            fill(s.data, s.data + SIZE, 0);
        }
    }
    return 0;
}
