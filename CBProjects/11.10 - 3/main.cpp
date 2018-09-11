#include <iostream>

using namespace std;

int arr[100][100], brr[100][100];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i; j++){
            if(!i){
                brr[j][j] = arr[j][j];
            }else
                brr[i + j][j] == min(brr[i + j - 1][j], min(brr[i + j][j + 1], arr[i + j][j]));
        }
        for(int j = i + 1; j < n; j++){
            if(i)
                brr[i + j][j] == min(brr[i + j + 1][j], min(brr[i + j][j - 1], arr[i + j][j]));
        }
    }
    return 0;
}
