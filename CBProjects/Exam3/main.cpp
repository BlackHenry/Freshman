#include <iostream>

using namespace std;

void func(char s[1000])
{
    int n = strlen(s);
    char s2[1000];
    int k = 0;
    for(int i = 0; i < n - 2; i++)
    {
        if(s[i] == 't' && s[i+1] == 'h' && s[i+2] == 'e')
        {
            i += 3;
            continue;
        }
        s2[k] = s[i];
        k++;
    }
    s2[k] = '/0';
    strcpy(s, s2);
}

int main()
{
    func("asddsdathe");
    return 0;
}
