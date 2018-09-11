#include <iostream>

using namespace std;

int n, w, h, arr[40][40];

int main()
{
    cin >> w >> h >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        for(int j = a - 1; j <= a + 1; j++){
            for(int h = b - 1; h <= b + 1; h++){
                if(arr[j][h]!=-1)
                    arr[j][h]++;
            }
        }
        arr[a][b] = -1;
    }
    for(int i = 1; i <= w; i++){
        for(int j = 1; j <= h; j++){
            if(arr[i][j] != -1)
                cout << arr[i][j] << " ";
            else
                cout << "* ";
        }
        cout << endl;
    }
    return 0;
}
