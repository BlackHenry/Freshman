#include <iostream>

using namespace std;

int main()
{
    int k = 0;
    for(int i = 1; i <= 250; i++){
        if(i%2&&i%3&&i%5&&i%7&&i%11&&i%13){
            k++;
        }
    }
    cout << k << endl;
    return 0;
}
