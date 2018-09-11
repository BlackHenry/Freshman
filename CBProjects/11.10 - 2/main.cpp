#include <iostream>
#include <vector>

using namespace std;
int n, last_remainder;
string result_string = "0.";

void div(int n){
    int k_2 = 0, k_5 = 0, t_n = n, pre_p;
    while(!(t_n % 2)){
        k_2++;
        t_n /= 2;
    }
    while(!(t_n % 5)){
        k_5++;
        t_n /= 5;
    }
    pre_p = max(k_2, k_5);
    int m = 1;
    for(int i = 0; i < pre_p; i++){
        result_string += to_string((10*m)/n);
        m = (m*10)%n;
    }
    result_string += "(";
    result_string += to_string((10*m)/n);
    m = (m*10)%n;
    last_remainder = m;

    do{
        result_string += to_string((10*m)/n);
        m = (m*10)%n;
    } while(m != last_remainder);
    result_string.pop_back();
    result_string += ")\n";
}

int main()
{
    cin >> n;
    div(n);
    cout << result_string;
    return 0;
}
