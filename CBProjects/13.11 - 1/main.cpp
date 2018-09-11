#include <iostream>

using namespace std;

bool is_div(long long n){
    for(long long i = 3; i <= n/i; i+=2){
        if(n%i == 0){
            cout << i << endl;
            return 1;
        }
    }
    return 0;
}

int main()
{
    long long a = 21181*2 + 1;
    for(int i = 0; i < 50; i++){
        if(!(is_div(a))){
            cout << a << "!!!!!\n";
        }
        a = a - 1;
        a *= 2;
        a += 1;
    }
    return 0;
}
