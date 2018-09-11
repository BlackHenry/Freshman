#include <iostream>

using namespace std;

bool func(char s1[1000], char s2[1000])
{
    int mask1[256] = {0};
    int len1 = strlen(s1);
    for(int i = 0; i < len1; i++)
    {
        mask1[s1[i]]++;
    }
    int mask2[256] = {0};
    int len2 = strlen(s2);
    for(int i = 0; i < len2; i++)
    {
        mask2[s1[i]]++;
    }
    for(int i = 0; i < 256; i++)
    {
        if(mask1[i] != mask2[i])
            return false;
    }
    return true;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
