#include <iostream>

using namespace std;

string rev(string s){
    if(s.size() == 1)
        return s;
    return rev(s.substr(1, s.size() - 1)) + s.substr(0, 1);
}

int main()
{
    string s;
    cin >> s;
    cout << rev(s) << endl;
    return 0;
}
