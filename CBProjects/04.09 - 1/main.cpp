#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a + b > c && b + c > a){
        cout << "Triangle's possible!" << endl;
        if(c * c < a * a + b * b && b * b < a * a + c * c && a * a < c * c + b * b)
            cout << "It's an acute-angled triangle!";
    }
    else
        cout << "Triangle's impossible!";

    return 0;
}
