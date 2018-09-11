#include <iostream>

using namespace std;

int func()
{
    FILE* p = fopen("input.txt", "r");
    char c;
    int k = 0;
    do {
        c = getc (p);
        if(c == '/n')
        {
            do {
                c = getc (p);
            } while (c == ' ' || c == '/t');
            if(c == '/n')
                k++;
        }
    } while (c != EOF);
    return k;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
