#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ofstream z("input.txt");
    vector<int> vr;
    for(int i = 0; i < 100000; i++){
        vr.push_back(i);
    }
    random_shuffle(vr.begin(), vr.end());
    for(int i = 0; i < 100000; i++){
        z << vr[i] << endl;
    }
    return 0;
}
