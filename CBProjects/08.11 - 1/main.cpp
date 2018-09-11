#include <iostream>

using namespace std;

bool is_pal(string s){
    if(s[0] != s.back())
        return 0;
    if(s.size() < 3){
        return 1;
    }
    return is_pal(s.substr(1, s.size() - 2));
}

int main()
{
    string s;
    cin >> s;
    if(is_pal(s)){
        cout << "String is a palindrome!\n";
        return 0;
    }
    cout << "String is not a palindrome!\n";
    return 0;
}
