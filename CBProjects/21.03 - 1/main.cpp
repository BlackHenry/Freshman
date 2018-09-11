#include <iostream>
#include "MyList.h"

using namespace std;

int main()
{
    MyList<int> a, b;
    MyList<int>::iterator it;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        a.add(i);
        a.add(i);
        a.add(i);
    }
    a.clean(b);
    cout << "a: " << endl;
    for(it = a.begin(); it != a.end(); it++){
        cout << (*it) << endl;
    }
    cout << "b: " << endl;
    for(it = b.begin(); it != b.end(); it++){
        cout << (*it) << endl;
    }
    return 0;
}
