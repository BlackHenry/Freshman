#include <iostream>
#include <list>
#include <map>

using namespace std;

int main()
{
    int arr[10] = {0, 1, 2, 6, 5, 3, 4, 7, 8, 9}
    list<pair<int, int> > input;
    for (int i = 0; i < 10; i++){
        input.push_back(make_pair(i, arr[i]));
    }

    return 0;
}
