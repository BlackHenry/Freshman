#include <iostream>

using namespace std;

bool A[100][100];
bool visited[10000];
int n;

int DFS(int nodeNumber){
    visited[nodeNumber] = 1;
    int a = 1;
    for (int i = 0; i < n; i++){
        if(i == nodeNumber)
            continue;
        if(A[nodeNumber][i] && !visited[i]){
            visited[i] = 1;
            a += DFS(i);
        }
    }
    return a;
}

bool Connected(){
    return (DFS(0) == n);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }
    cout << Connected() << endl;
    return 0;
}
