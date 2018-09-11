#include <iostream>

using namespace std;

int func()
{
    FILE* p = fopen("input.txt", "r");
    char c1 = 0, c2 = 0;
    int k = 0;
    do {
        c1 = getc (p);
        if((c1 == '/'||c1 == '*')&&c2 == '/')
            k++;
        c2 = c1;
    } while (c1 != EOF);
    return k;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
