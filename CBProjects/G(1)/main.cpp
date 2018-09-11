#include <iostream>

using namespace std;

long long int arr[2010], n0, m, crr[2000005];
short int brr[500005];

void bt(int n, int l, int r){
    if(l == r){
        crr[n] = brr[l];
        return;
    }
    int m = (l + r) / 2;
    bt(2*n, l, m);
    bt(2*n + 1, m + 1, r);
    crr[n] = crr[2*n] + crr[2*n + 1];
    return;
}

int sum(int n, int l, int r, int l1, int r1){
    //cerr << n << " " << l << " " << r << " " << l1 << " " << r1 << endl;
    if(l == l1 && r == r1){
        return crr[n];
    }
    int m = (l1 + r1)/2;
    if(l <= m && r <= m)
        return sum(2*n, l, r, l1, m);
    if(l > m && r > m)
        return sum(2*n+1, l, r, m + 1, r1);
    return sum(2*n, l, m, l1, m) + sum(2*n+1, m + 1, r, m + 1, r1);
}

void ch(int n, int i, int d, int l, int r){
    crr[n] += d;
    //cerr << n << " " << i << " " << d << " " << l << " " << r << endl;
    if(l == r)
        return;
    int m = (l + r)/2;
    if(i <= m)
        ch(2*n, i, d, l, m);
    if(i > m)
        ch(2*n + 1, i, d, m + 1, r);
    return;
}

int main()
{
    string s;
    for(int i = 0; i < 2010; i++){
        arr[i] = (i*i)%2010;
    }
    cin >> n0;
    for(int i = 0; i < n0; i++){
        scanf("%d", &brr[i]);
    }
    bt(1, 0, n0-1);
    //for(int i = 0; i < 4*n; i++){cerr << crr[i] << endl; }
    cin >> m;
    for(int i = 0; i < m; i++){
        int a, l, r;
        scanf("%d %d %d", &a, &l, &r);
        l--;
        r--;
        if(a == 1){
            for(int j = l; j <= r; j++){
                ch(1, j, arr[brr[j]]- brr[j], 0, n0-1);
                brr[j] = arr[brr[j]];
            }
            //for(int h = 0; h < 4*n; h++){cerr << crr[h] << endl; }
        }
        if(a == 2){
            s += to_string(sum(1, l, r, 0, n0-1));
            s+= "\n";
        }
    }
    cout << s;
    return 0;
}
