#include <iostream>
#include <list>
#include <vector>

using namespace std;

int n, m;
vector<list<int> > sorted_matrix;

int main()
{
    cin >> n >> m;
    sorted_matrix.resize(n);
    for(int i = 0; i < n; i++){
        int k0 = 0;
        for(int j = 0; j < m; j++){
            int a;
            cin >> a;
            if(a > 0){
                sorted_matrix[i].push_back(a);
            }
            if(a < 0){
                sorted_matrix[i].push_front(a);
            }
            if(!a){
                k0++;
            }
        }
        for(int j = 0; j < k0; j++){
            sorted_matrix[i].push_back(0);
        }
    }
    for(int i = 0; i < n; i++){
        for(auto it: sorted_matrix[i]){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
