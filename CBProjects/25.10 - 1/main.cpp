#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

float n;

void print_digit(int digit){
    switch(digit){
    case 1:
        cout << "Один ";
        break;
    case 2:
        cout << "Два ";
        break;
    case 3:
        cout << "Три ";
        break;
    case 4:
        cout << "Чотири ";
        break;
    case 5:
        cout << "П'ять ";
        break;
    case 6:
        cout << "Шiсть ";
        break;
    case 7:
        cout << "Сiм ";
        break;
    case 8:
        cout << "Вiсiм ";
        break;
    case 9:
        cout << "Дев'ять ";
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
            cout << "Двадцять ";
            break;
        case 3:
            cout << "Тридцять ";
            break;
        case 4:
            cout << "Сорок ";
            break;
        case 5:
            cout << "П'ятдесят ";
            break;
        case 6:
            cout << "Шiстдесят ";
            break;
        case 7:
            cout << "Сiмдесят ";
            break;
        case 8:
            cout << "Вiсiмдесят ";
            break;
        case 9:
            cout << "Дев'яносто ";
            break;
        }
        print_digit(ten%10);
        return;
    }
    switch(ten){
    case 10:
        cout << "Десять ";
        break;
    case 11:
        cout << "Одиннадцять ";
        break;
    case 12:
        cout << "Дванадцять ";
        break;
    case 13:
        cout << "Тринадцять ";
        break;
    case 14:
        cout << "Чотирнадцять ";
        break;
    case 15:
        cout << "П'ятнадцять ";
        break;
    case 16:
        cout << "Шiстнадцять ";
        break;
    case 17:
        cout << "Сiмнадцять ";
        break;
    case 18:
        cout << "Вiсiмнадцять ";
        break;
    case 19:
        cout << "Дев'ятнадцять ";
        break;
    }
}

void print_hundred(int number){
    if(a > 99){
        int k = number/100;
        switch(k){
        case 1:
            cout << "Сто ";
            break;
        case 2:
            cout << "Двiстi ";
            break;
        case 3:
            cout << "Триста ";
            break;
        case 4:
            cout << "Чотириста ";
            break;
        case 5:
            cout << "П'ятсот ";
            break;
        case 6:
            cout << "Шiстсот ";
            break;
        case 7:
            cout << "Сiмсот ";
            break;
        case 8:
            cout << "Вiсiмсот ";
            break;
        case 9:
            cout << "Дев'ятсот ";
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
        cout << "Тис. ";
        break;
    case 3:
        cout << "Млн. ";
        break;
    case 4:
        cout << "Млрд. ";
        break;
    case 5:
        cout << "Трлн. ";
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
