#include <iostream>
#include <unordered_map>

using namespace std;

int n, m;

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int min_el = 1e9, max_el = -1e9, a, b, loc_min;
        unordered_map<int, int> seq;
        for(int j = 0; j < m; j++){
            if(!j){
                cin >> a;
                seq[a] = a;
                loc_min = a;
                continue;
            }
            cin >> b;
            if(b > a){
                seq[loc_min] = b;
            }
            else{
                min_el = min(min_el, loc_min);
                max_el = max(max_el, a);
                loc_min = b;
                seq[b] = b;
            }
            a = b;
        }
        max_el = max(max_el, b);
        if(seq[min_el] == max_el){
            cout << i + 1 << endl;
        }
    }
    return 0;
}
