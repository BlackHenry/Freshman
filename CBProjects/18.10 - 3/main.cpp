#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<int> row_without_dublicates;
int n, m;

int main()
{
    cin >> n >> m;;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int a;
            cin >> a;
            row_without_dublicates.insert(a);
        }
        if(row_without_dublicates.size() == m){
            cout << i + 1 << endl;
        }
        row_without_dublicates.clear();
    }
    return 0;
}
