#include <iostream>

using namespace std;

struct Stack{
    int size = 0;
    int data[100000];
}s;

int F(int m, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            s.data[i + j] = i*j ? i + j + 1: s.data[i - 1 + s.data[m + n - 1]];
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
