#include <iostream>
#include "MyList.h"

using namespace std;

int main()
{
    int n, m;
    MyList<int> cycled_list = MyList<int>();
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cycled_list.add(i);
    }
    cycled_list.cycle();
    MyList<int>::iterator it = MyList<int>::iterator(cycled_list.begin());
    while(cycled_list.size()){
        for(int i = 1; i < m; i++){
            it++;
        }
        int element = (*it);
        it++;
        cout << element << endl;
        cycled_list.remove(element);
    }
    return 0;
}
