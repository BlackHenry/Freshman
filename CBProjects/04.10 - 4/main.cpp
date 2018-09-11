#include <iostream>
#include <map>

#include <cstdlib>
#include <ctime>

using namespace std;

int sum, n;

map<int, int> mp;

void print_map(map<int, int> m){
    cout << endl;
    for(auto i: m){
        cout << i.first << " " << i.second << endl;
    }
    cout << "\n";
}

bool dp(map<int, int> m, int l, int min_el){

    int s = 0;
    bool a;
    for(auto it: m){
        s += it.first * it.second;
    }
    cout << l << " " << s << endl;
    if(s == sum){
        print_map(m);
        return 1;
    }
    if(l == 0 || s < sum){
        return 0;
    }
    for(auto it: m){
        if(it.second == 0 || it.first < min_el)
            continue;
        map<int, int> m1 = m;
        m1[it.first]--;
        //print_map(m1);
        a = dp(m1, l - 1, it.first) || a;
    if(a) return 1;
    }
    return a;
}

int main()
{
    int l0;
    cin >> n >> sum;
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        int a, b;
        //cin >> a >> b;
        a=rand()%10000+1;
        b=rand()%100+1;
        cerr << a << ' ' << b << endl;
        mp[a] = b;
        l0 += b;
    }
    cout << dp(mp, l0, 0);
    return 0;
}
