#include <iostream>

using namespace std;

int* func(int A[1000], int B[1000], int lenA, int lenB)
{
    int C[1000] = {0};
    bool arr[2000000000] = {0};
    for(int i = 0; i < lenB; i++)
    {
        arr[B[i]] = true;
    }
    int k = 0;
    for(int i = 0; i < lenA; i++)
    {
        if(arr[A[i]] == false)
        {
            C[k] = A[i];
            k++;
        }
    }
    return C;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
