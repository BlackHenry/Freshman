#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector <int> vrr;

void print_vector(){
    for(int i = 0; i < vrr.size(); i++){
        cout << vrr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        vrr.push_back(a);
    }
    for(int i = 0; i < (int)tgamma(n + 1); i++){
        next_permutation(vrr.begin(), vrr.end());
        print_vector();
    }
    return 0;
}
