#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map <char, int> numbers;
string input;
// = {("I", 1),("V", 5),("X", 10),("L", 50),("C", 100),("D", 500),("M", 1000)};

int main()
{
    numbers['I'] = 1;
    numbers['V'] = 5;
    numbers['X'] = 10;
    numbers['L'] = 50;
    numbers['C'] = 100;
    numbers['D'] = 500;
    numbers['M'] = 1000;
    cin >> input;
    int highest_val = 0, num_of_chars = 0, sum = 0;
    for(int i = input.size() - 1; i >= 0; i--){
        char c = input[i];
        if(!highest_val){
            highest_val = numbers[c];
            num_of_chars++;
            sum = highest_val;
            continue;
        }
        if(numbers[c] < highest_val){
            if(c == input[i+1]){
                cout << "Incorrect input!\n";
                return 0;
            }
            sum -= numbers[c];
            continue;
        }
        if(c == input[i+1]){
            num_of_chars++;
            if(num_of_chars > 3){
                cout << "Incorrect input!\n";
                return 0;
            }
        }
        else{
            num_of_chars = 1;
        }
        sum += numbers[c];
        highest_val = max(highest_val, numbers[c]);
    }
    cout << sum << endl;
    return 0;
}
