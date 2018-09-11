#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int arr[1000];
int a;

int func(int bl, int br){
    int l = br - bl;
    if(br - bl <= 1){
        return br * (arr[br] == a) + bl * (arr[bl] == a) * (bl != br);
    }
    if(bl[arr] <= a && br[arr] >= a)
        return func(bl + floor(l/2.0) + 1, br) + func(bl, br - ceil(l/2.0));
    return 0;
}

int main()
{
    for(int i = 0; i < 1000; i++){
        arr[i] = i * 2;
    }
    cin >> a;
    cout << func(0, 999);
    return 0;
}
