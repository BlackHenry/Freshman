#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, int> mp;
    string s = "asdada";
    FILE* f = fopen("save.txt", "wb");
    mp.insert(make_pair(s, 1));
    map<string, int>::iterator it = mp.begin();
    fwrite(&(it->first), sizeof(string),1, f);
    cout << "Hello world!" << endl;
    return 0;
}
