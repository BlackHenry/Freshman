#include <iostream>

using namespace std;

int n;
string s = "a";
char arr[3] = {'a', 'b', 'c'};

bool check(char b){
    s += b;
    for(int i = 1; i <= s.size()/2; i++){
        if(s.substr(s.size() - i, i) == s.substr(s.size() - 2*i, i)){
            s.pop_back();
            return false;
        }
    }
    return true;
}

bool build_str(int n){
    if(!n)
        return 1;
    bool a = 0;
    for(int i = 0; i < 3; i++){
        if(check(arr[i])){
            a = a || build_str(n-1);
        }
        if(a)
            return 1;
    }
    s.pop_back();
    return 0;
}

int main()
{
    cin >> n;
    build_str(n - 1);
    cout << s << " " << s.size() << endl;
    return 0;
}
