#include <iostream>

using namespace std;

string s1, s2;

int d(int i, int j){
    if(i == 0 && j == 0)
        return 0;
    if(i == 0)
        return j;
    if(j == 0)
        return i;
    int a = d(i, j - 1) + 1;
    int b = d(i - 1, j) + 1;
    int c = d(i - 1, j - 1) + 2*(!(s1[i-1] == s2[j-1]));
    return min(min(a, b), c);
}

int main()
{
    cin >> s1 >> s2;
    cout << d(s1.size(), s2.size()) << endl;
    return 0;
}
