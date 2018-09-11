#include <iostream>
#include <cstring>

using namespace std;

char s[100], t[100], result[100];
bool arr[256];
int k;

int main()
{
    cin >> s >> t;
    int n = strlen(t), m = strlen(s);
    for(int i = 0; i < n; i++){
        arr[t[i]] = 1;
    }
    for(int i = 0; i < m; i++){
        if(!arr[s[i]]){
            result[k] = s[i];
            k++;
        }
    }
    result[k] = '\0';
    strcpy(s, result);
    cout << s << endl;
    return 0;
}
