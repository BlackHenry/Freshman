#include <iostream>
#include <vector>

using namespace std;

vector<int> vrr;
int n, m;

int main()
{
    int k = 0;
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int a, b;
            cin >> a;
            if(j){
                if(i){
                    if(a + b + vrr[j - 1] == 17)
                        k++;
                    vrr[j-1] = a + b;
                }
                else
                    vrr.push_back(a + b);
            }
            b = a;
        }
    }
    cout << k;
    return 0;
}
