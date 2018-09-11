#include <fstream>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    ofstream z("save.txt");
    srand(time(0));
    for(int k = 0; k < 100000; k++){
        int n0 = rand()%500 + 1;
        cout << n0 << endl;
        z << n0 << endl;
        for(int i = 0; i < n0; i++){
            z << rand()%2010 << " ";
        }
        z << endl;
        int n = rand()%500;
        z << n << endl;
        for (int i = 0; i < n; i++){
            int a = rand()%n0;
            int b = rand()%n0;
            z << rand()%2 + 1 << " " << min(a,b) << " " << max(a, b) << endl;
        }
    }
    return 0;
}
