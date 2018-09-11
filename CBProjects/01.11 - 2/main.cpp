#include <iostream>

using namespace std;

int arr[100][100], temp_arr[100][100];
bool brr[100][100], temp_brr[100][100];

int n, m, k;

void print_state(bool t = 1){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(t)
                cout << (int)arr[i][j] << " ";
            else
                cout << (int)brr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void copymas(bool b = 1){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(b){
                arr[i][j] = temp_arr[i][j];
                brr[i][j] = temp_brr[i][j];
            }
            else{
                temp_arr[i][j] = arr[i][j];
                temp_brr[i][j] = brr[i][j];
            }
        }
    }
}

void change_cells(int x, int y, bool b = 1, bool b1 = 0){
    int i = 0, j = 0, imax = n - 1, jmax = m - 1;
    if(x){
        i = x - 1;
    }
    if(y){
        j = y - 1;
    }
    if(n-1-x){
        imax = x + 1;
    }
    if(m-1-y){
        jmax = y + 1;
    }
    for(; i <= imax; i++){
        for(; j <= jmax; j++){
            if(i==x&&j==y){
                continue;
            }
            if(b){
                if(b1)
                    arr[i][j]++;
                else
                    temp_arr[i][j]++;
            }
            else{
                temp_arr[i][j] = max(0, arr[i][j] - 1);
            }
        }
    }
}

void evolve(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(brr[i][j]){
                if(arr[i][j] < 2 && arr[i][j] > 3){
                    temp_brr[i][j] = 0;
                    change_cells(i, j, 0);
                }
            }
            else{
                if(arr[i][j] == 3){
                    temp_brr[i][j] = 1;
                    change_cells(i, j);
                }
            }
        }
    }
    copymas();
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> brr[i][j];
            if(brr[i][j]){
                change_cells(i, j, 1, 1);
            }
        }
    }
    copymas(0);
    for(int i = 0; i < k; i++){
        evolve();
        print_state();
        print_state(0);
    }
    return 0;
}
