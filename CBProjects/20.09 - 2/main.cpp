#include <iostream>
#include <vector>
using namespace std;
// ((((1?2)?3)?4)?5)?6 ? = + - * /

typedef enum{pl = 0, mi, mu, di} op;
vector<string> vs = {"+", "-", "*", "/"};

int target, max_length;

string s;

int dp(int n, op o, int l){
    if(l == max_length){
        if(n / (max_length + 1) == target){
            cout << n << "\n";
            cout << "/" << endl;
        return -1;
        }
        if(n * (max_length + 1) == target){
            cout << n << "\n";
            cout << "*" << endl;
        return -1;
        }
        if(n + (max_length + 1) == target){
            cout << n << "\n";
            cout << "+" << endl;
        return -1;
        }
        if(n - (max_length + 1) == target){
            cout << n << "\n";
            cout << "-" << endl;
        return -1;
        }
        return 0;
    }
    if(dp(n/(l + 1), di, l + 1) == -1){
        cout << vs[o] << endl;
        return -1;
    }
    if(dp(n*(l + 1), mu, l + 1) == -1){
        cout << vs[o] << endl;
        return -1;
    }
    if(dp(n+(l + 1), pl, l + 1) == -1){
        cout << vs[o] << endl;
        return -1;
    }
    if(dp(n-(l + 1), mi, l + 1) == -1){
        cout << vs[o] << endl;
        return -1;
    }
}

int main()
{
    cin >> max_length >> target;
    int a = dp(1, pl, 1);
    return 0;
}
