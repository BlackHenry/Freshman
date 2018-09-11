#include <iostream>
#include <vector>
#include <list>

using namespace std;

FILE* f;
list<int> vr_open, vr_close;

int main()
{
    f = fopen("input.txt", "r");
    if (f==NULL)
        perror ("Error opening file");
    else
    {
        int i = 0;
        char c;
        do{
            c = getc (f);
            if(c == '(')
                vr_open.push_back(i);
            if(c == ')')
                vr_close.push_back(i);
            i++;
        } while (c != EOF);
        fclose (f);
    }
    while(vr_open.size() && vr_close.size()){
        if(vr_close.back() > vr_open.front()){
            vr_open.pop_front();
            vr_close.pop_back();
        }
        else
            break;
    }
    if(vr_open.size() || vr_close.size()){
        cout << "Correct!\n";
    }
    else{
        cout << "Incorrect!\n";
    }
    return 0;
}
