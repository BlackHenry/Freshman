#include <iostream>

using namespace std;

int n, matrix[1000][1000];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        int min_el = 10000000;
        for(int j = 0; j <= i; j++){
            min_el = min(min_el, matrix[n - 1 - j][n - i - 1 + j]);
        }
        cout << min_el << endl;
    }
    for(int i = n-2; i >= 0; i--){
        int min_el = 10000000;
        for(int j = 0; j <= i; j++){
            min_el = min(min_el, matrix[i - j][j]);
        }
        cout << min_el << " ";
    }
    return 0;
}
