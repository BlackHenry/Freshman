#include <iostream>

using namespace std;

int n, arr[5500];

int S(int a){
    int s = 0;
    for(int i = 2; i <= a/i; i++){
        while(!(a%i)){
            s += i;
            a /= i;
        }
        if(a == 1)
            break;
    }
    if(a - 1){
        s += a;
    }
    return s;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        arr[i] = S(i);
    }
    arr[1] = 1;
    for(int h = 0; h < 10; h++)
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(i + j > n) continue;
            arr[i + j] = min(arr[i + j], arr[i] + arr[j]);
            if(i * j > n) continue;
            arr[i * j] = min(arr[i * j], arr[i] + arr[j]);
        }
    }
    //for(int i = 1; i <= n; i++) cout << i << " " << arr[i] << endl;
    cout << arr[n] << endl;
    return 0;
}
