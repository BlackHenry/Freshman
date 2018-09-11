#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map <long long, int> freq_map;

long long b_power(long long a, long long mod){
    for(int i = 0; i < 3; i++){
        a = (a*a) % mod;
    }
    return a;
}

long long hash_f(vector<int> arg){
    long long sum = 0;
    for(int i = 0; i < arg.size(); i++){
        sum += b_power(arg[i], 10000000);
    }
    return sum;
}

int main()
{
    int a;
    long long first_hash;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        vector<int> temp;
        for(int j = 0; j < m; j++){
            cin >> a;
            temp.push_back(a);
        }
        long long temp_hash = hash_f(temp);
        if(i == 0){
            first_hash = temp_hash;
        }
        freq_map[temp_hash]++;
    }
    cout << freq_map[first_hash] << endl;
    return 0;
}
