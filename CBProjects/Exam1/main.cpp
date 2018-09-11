#include <iostream>

using namespace std;

int func(int A[1000][1000], int n, int m)
{
    int k = 0;
    bool t;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            t = false;
            for(int h = 0; h < j; h++)
            {
                if(A[i][h] >= A[i][j])
                {
                    t = true;
                    break;
                }
            }
            if(t) continue;
            for(int h = j + 1; h < m; h++)
            {
                if(A[i][h] <= A[i][j])
                {
                    t = true;
                    break;
                }
            }
            if(t) continue;
            k++;
        }
    }
    return k;
}

int main()
{
    cout << "Hello world!" << endl;

    return 0;
}
