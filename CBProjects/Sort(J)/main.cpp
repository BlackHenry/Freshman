#include <iostream>
#include <list>

using namespace std;

int n;
list<int> arr, brr;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        brr.push_back(a);
    }
    arr.push_back(2e9);
    brr.push_back(2e9);
    for(int i = 0; i < 2*n; i++){
        if(arr.front() <= brr.front()){
            cout << arr.front() << " ";
            arr.pop_front();
        }
        else{
            cout << brr.front() << " ";
            brr.pop_front();
        }
    }
    return 0;
}
