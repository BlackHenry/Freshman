#include <iostream>

using namespace std;

int arr[2010], brr[50005], prr[50005], n0, m;

void bp(){
    prr[0] = brr[0];
    for(int i = 1; i < n0; i++){
        prr[i] = prr[i-1] + brr[i];
    }
}

int sp(int l, int r){
    if(l == 0)
        return prr[r];
    return prr[r] - prr[l - 1];
}

int main()
{
    for(int i = 0; i < 2010; i++){
        arr[i] = (i*i)%2010;
    }
    cin >> n0;
    for(int i = 0; i < n0; i++){
        scanf("%d", &brr[i]);
    }
    bp();
    //for(int i = 0; i < 4*n; i++){cerr << crr[i] << endl; }
    cin >> m;
    for(int i = 0; i < m; i++){
        int a, l, r;
        scanf("%d %d %d", &a, &l, &r);
        l--;
        r--;
        if(a == 1){
            for(int j = l; j < n0; j++){
                if(j <= r){
                    brr[j] = arr[brr[j]];
                }
                prr[j] = prr[j-1] + brr[j];
            }
        }
        if(a == 2){
            printf("%d\n", sp(l, r));
        }
    }
    return 0;

}
