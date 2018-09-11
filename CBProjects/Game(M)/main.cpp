#include <iostream>

using namespace std;

int n;

int main()
{
    int s = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> b >> a;
        s ^= (a%2)*b;
    }
    if(s){
        cout << "Karlson\n";
        return 0;
    }
    cout << "Little Boy\n" << endl;
    return 0;
}
