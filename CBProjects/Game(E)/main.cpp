#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(a^b){
            cout << 1;
        }
        else{
            cout << 2;
        }
    }
    return 0;
}
