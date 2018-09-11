#include <iostream>

using namespace std;

/*

*
**
*
*

****
  *

*/

bool arr[100][100], t;

bool put_fig(int x, int y, int orient, bool rem = 1){
    switch(orient){
    case 1:
        if(x < 3 || y > m - 2)
            return 0;
        if(arr[x][y]||arr[x-1][y]||arr[x-2][y]||arr[x-3][y]||arr[x-2][y+1])
            return 0;
        arr[x][y] = rem;
        arr[x-1][y] = rem;
        arr[x-2][y] = rem;
        arr[x-3][y] = rem;
        arr[x-2][y+1] = rem;
        return 1;
        break;
    case 2:
        if(x > n - 2 || y > m - 4)
            return 0;
        if(arr[x][y]||arr[x][y+1]||arr[x][y+2]||arr[x][y+3]||arr[x+1][y+2])
            return 0;
        arr[x][y] = rem;
        arr[x][y+1] = rem;
        arr[x][y+2] = rem;
        arr[x][y+3] = rem;
        arr[x+1][y+2] = rem;
        return 1;
        break;
    case 3:
        if(x > n - 4 || y < 1)
            return 0;
        if(arr[x][y]||arr[x+1][y]||arr[x+2][y]||arr[x+3][y]||arr[x+2][y-1])
            return 0;
        arr[x][y] = rem;
        arr[x+1][y] = rem;
        arr[x+2][y] = rem;
        arr[x+3][y] = rem;
        arr[x+2][y-1] = rem;
        return 1;
        break;
    case 4:
        if(x < 1 || y < 3)
            return 0;
        if(arr[x][y]||arr[x][y-1]||arr[x][y-2]||arr[x][y-3]||arr[x-1][y-2])
            return 0;
        arr[x][y] = rem;
        arr[x][y-1] = rem;
        arr[x][y-2] = rem;
        arr[x][y-3] = rem;
        arr[x-1][y-2] = rem;
        return 1;
        break;
    case 5:
        if(x < 3 || y < 1)
            return 0;
        if(arr[x][y]||arr[x-1][y]||arr[x-2][y]||arr[x-3][y]||arr[x-2][y-1])
            return 0;
        arr[x][y] = rem;
        arr[x-1][y] = rem;
        arr[x-2][y] = rem;
        arr[x-3][y] = rem;
        arr[x-2][y-1] = rem;
        return 1;
        break;
    case 6:
        if(x < 1 || y > m - 4)
            return 0;
        if(arr[x][y]||arr[x][y+1]||arr[x][y+2]||arr[x][y+3]||arr[x-1][y+2])
            return 0;
        arr[x][y] = rem;
        arr[x][y+1] = rem;
        arr[x][y+2] = rem;
        arr[x][y+3] = rem;
        arr[x-1][y+2] = rem;
        return 1;
        break;
    case 7:
        if(x > n - 4 || y > n - 2)
            return 0;
        if(arr[x][y]||arr[x+1][y]||arr[x+2][y]||arr[x+3][y]||arr[x+2][y+1])
            return 0;
        arr[x][y] = rem;
        arr[x+1][y] = rem;
        arr[x+2][y] = rem;
        arr[x+3][y] = rem;
        arr[x+2][y+1] = rem;
        return 1;
        break;
    case 8:
        if(x > n - 2 || y < 3)
            return 0;
        if(arr[x][y]||arr[x][y-1]||arr[x][y-2]||arr[x][y-3]||arr[x+1][y-2])
            return 0;
        arr[x][y] = rem;
        arr[x][y-1] = rem;
        arr[x][y-2] = rem;
        arr[x][y-3] = rem;
        arr[x+1][y-2] = rem;
        return 1;
        break;
    }
}

bool solve(int s){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int h = 1; h < 9; h++){
                if(put_fig(i, j, h)){
                    solve(s + 5);
                    put_fig(i, j, h, 0);
                }
            }
        }
    }
    if(s == s0 && !t)
    {
        cout << "Possible!\n";
        t = true;
    }
    return 0;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
