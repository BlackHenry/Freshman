#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

float n;

void print_digit(int digit){
    switch(digit){
    case 1:
        cout << "���� ";
        break;
    case 2:
        cout << "��� ";
        break;
    case 3:
        cout << "��� ";
        break;
    case 4:
        cout << "������ ";
        break;
    case 5:
        cout << "�'��� ";
        break;
    case 6:
        cout << "�i��� ";
        break;
    case 7:
        cout << "�i� ";
        break;
    case 8:
        cout << "�i�i� ";
        break;
    case 9:
        cout << "���'��� ";
        break;
    }
}

void print_ten(int ten){
    if(ten < 10){
        print_digit(ten);
        return;
    }
    if(ten >= 20){
        int k = ten/10;
        switch(k){
        case 2:
            cout << "�������� ";
            break;
        case 3:
            cout << "�������� ";
            break;
        case 4:
            cout << "����� ";
            break;
        case 5:
            cout << "�'������� ";
            break;
        case 6:
            cout << "�i������� ";
            break;
        case 7:
            cout << "�i������ ";
            break;
        case 8:
            cout << "�i�i������ ";
            break;
        case 9:
            cout << "���'������ ";
            break;
        }
        print_digit(ten%10);
        return;
    }
    switch(ten){
    case 10:
        cout << "������ ";
        break;
    case 11:
        cout << "����������� ";
        break;
    case 12:
        cout << "���������� ";
        break;
    case 13:
        cout << "���������� ";
        break;
    case 14:
        cout << "������������ ";
        break;
    case 15:
        cout << "�'��������� ";
        break;
    case 16:
        cout << "�i��������� ";
        break;
    case 17:
        cout << "�i�������� ";
        break;
    case 18:
        cout << "�i�i�������� ";
        break;
    case 19:
        cout << "���'��������� ";
        break;
    }
}

void print_hundred(int number){
    if(a > 99){
        int k = number/100;
        switch(k){
        case 1:
            cout << "��� ";
            break;
        case 2:
            cout << "��i��i ";
            break;
        case 3:
            cout << "������ ";
            break;
        case 4:
            cout << "��������� ";
            break;
        case 5:
            cout << "�'����� ";
            break;
        case 6:
            cout << "�i����� ";
            break;
        case 7:
            cout << "�i���� ";
            break;
        case 8:
            cout << "�i�i���� ";
            break;
        case 9:
            cout << "���'����� ";
            break;
        }
        number %= 100;
    }
    print_ten(number);
}

void print_thousand(int thousand, int exp){
    print_hundred(thousand);
    if(exp == 1){
        return;
    }
    switch(exp){
    case 2:
        cout << "���. ";
        break;
    case 3:
        cout << "���. ";
        break;
    case 4:
        cout << "����. ";
        break;
    case 5:
        cout << "����. ";
        break;
    }
}

int main()
{
    setlocale(LC_CTYPE, "");
    cin >> n;
    if(floor(n) != n){

    }
    return 0;
}
