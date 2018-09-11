#include <iostream>

using namespace std;

struct DoubleStack{
    int first_size = 0;
    int second_size = 0;
    int data[100] = {0};
}d_s;

void Fill(DoubleStack &d, int i, int j){
    if(j > 0){
        if(d.first_size + d.second_size + 1 > 100){
            cout << "Stack overflow!\n";
            return;
        }
        if(j == 1){
            d.data[d.first_size] = i;
            d.first_size++;
        }
        if(j == 2){
            d.data[99 - d.second_size] = i;
            d.second_size++;
        }
    }
    if (j == -1){
        if(d.first_size == 0){
            cout << "Nothing to delete\n";
            return;
        }
        d.data[--d.first_size] = 0;
    }
    if (j == -2){
        if(d.second_size == 0){
            cout << "Nothing to delete\n";
            return;
        }
        d.data[99 - (--d.second_size)] = 0;
    }
}

void print(DoubleStack d){
    for(int i = 0; i < 100; i++){
        cout << d.data[i] << " ";
    }
    cout << endl;
}

int main()
{
    Fill(d_s, 2, 1);
    Fill(d_s, 9, 1);
    Fill(d_s, 3, 2);
    Fill(d_s, 4, 2);
    Fill(d_s, 8, 2);
    Fill(d_s, 2, -1);
    Fill(d_s, 2, 1);
    Fill(d_s, 2, -2);
    print(d_s);
    return 0;
}
