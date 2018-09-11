#include <iostream>

using namespace std;

int func(int A[1000][1000], int sizeX, int sizeY)
{
    bool bitmask[1000000] = {0};
    int mx = -1e9;
    for(int i = 0; i < sizeX; i++)
    {
        for(int j = 0; j < sizeY; j++)
        {
            if(bitmask[A[i][j]])
            {
                mx = max(mx, A[i][j]);
            }
            else
                bitmask[A[i][j]] = 1;
        }
    }
    return mx;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
