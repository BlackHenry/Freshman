#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

char s[100];
long long int f;
int n, e;

void string_to_float(){
    int i = 0;
    bool t = 0;
    if(s[0] == '-'){
        t = 1;
        i++;
    }
    while(isdigit(s[i]) && i < n){
        f *= 10;
        f += s[i] - '0';
        i++;
    }
    if(i == n)
        return;
    i++;
    while(isdigit(s[i]) && i < n){
        f *= 10;
        f += s[i] - '0';
        i++;
        e--;
    }
    if(i == n)
        return;
    i++;
    bool t2 = 0;
    if(s[i] == '-'){
        t2 = 1;
        i++;
    }
    int temp_exp = 0;
    while(isdigit(s[i]) && i < n){
        temp_exp *= 10;
        temp_exp += s[i] - '0';
        i++;
    }
    if(t2) temp_exp*=-1;
    if(t) f*=-1;
    e += temp_exp;
}

int main()
{
    cin >> s;
    n = strlen(s);
    char temp[100];
    int k_temp = 0;
    bool dot = 1, ex = 1;
    for(int i = 0; i < n; i++){
        if(isdigit(s[i])){
            temp[k_temp] = s[i];
            k_temp++;
        }
        if(s[i] == '.' && dot){
            temp[k_temp] = '.';
            k_temp++;
            dot = 0;
        }
        if((s[i] == 'e' || s[i] == 'E') && ex){
            temp[k_temp] = 'e';
            k_temp++;
            ex = 0;
        }
    }
    strcpy(s, temp);
    n = k_temp;
    string_to_float();
    long double d = double(f) * pow(10, e);
    cout << d << endl;
    return 0;
}
