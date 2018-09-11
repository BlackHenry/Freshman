#include <iostream>

using namespace std;

bool last_row[100], last_char;
int n, m, k;

int main()
{
    cin >> n >> m;
    char c;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            bool a = 0;
            cin >> c;
            if(c == '#'){
                a = 1;
            }
            if(a && !last_char && !(last_row[j])){
                k++;
            }
            last_char = a;
            last_row[j] = a;
        }
    }
    cout << k << endl;
    return 0;
}
