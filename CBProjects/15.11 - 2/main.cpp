#include <iostream>

using namespace std;

int desk[8][8], n;

void rem(int x, int y){
    desk[x][y] = 4;
    for(int i = 0; i < 8; i++){
        desk[i][y] = max(0, desk[i][y]--);
        desk[x][i] = max(0, desk[x][i]--);
        if(x + i < 8 && y + i < 8){
            desk[x + i][y + i] = max(0, desk[x + i][y + i]--);
        }
        if(x - i >= 0 && y + i < 8){
            desk[x - i][y + i] = max(0, desk[x - i][y + i]--);
        }

        if(x + i < 8 && y - i >= 0){
            desk[x + i][y - i] = max(0, desk[x + i][y - i]--);
        }

        if(x - i >= 0 && y - i >= 0){
            desk[x - i][y - i] = max(0, desk[x - i][y - i]--);
        }
        if(desk[i][y] > 100){
            desk[i][y] = 10000;
        }
        if(desk[x][i] > 100){
            desk[x][i] = 10000;
        }
    }
}

void place(int x, int y){
    desk[x][y] = 10000;
    for(int i = 0; i < 8; i++){
        desk[i][y]++;
        desk[x][i]++;
        if(x + i < 8 && y + i < 8){
            desk[x + i][y + i]++;
        }
        if(x - i >= 0 && y + i < 8){
            desk[x - i][y + i]++;
        }

        if(x + i < 8 && y - i >= 0){
            desk[x + i][y - i]++;
        }

        if(x - i >= 0 && y - i >= 0){
            desk[x - i][y - i]++;
        }
    }
}

bool try_place(int k){
    if(!k)
        return 1;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(!desk[i][j]){
                place(i, j);
                if(try_place(k-1))
                    return 1;
                rem(i, j);
            }
        }
    }
    return 0;
}

int main()
{
    cin >> n;
    if(!try_place(n)){
        cout << "Impossible!\n";
        return 0;
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(desk[i][j] > 1000)
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
