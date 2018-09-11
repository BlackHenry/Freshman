#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pupil{
    string sur, name, form_s, date;
    int form;
    Pupil(string a="", string b="", int c=0, string c1="", string d=""): sur(a), name(b), form(c), form_s(c1), date(d) {}
};

int n;
vector<Pupil> pupils;

bool c(Pupil a, Pupil b){
    if(a.form == b.form){
        if(a.form_s == b.form_s)
            return a.sur <= b.sur;
        return a.form_s <= b.form_s;
    }
    return a.form <= b.form;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        string s1, s2, s3, s4, s5;
        cin >> s1 >> s2 >> s3 >> s4;
        s5 = s3.back();
        s3.pop_back();
        pupils.emplace_back(s1, s2, stoi(s3), s5, s4);
    }
    sort(pupils.begin(), pupils.end(), c);
    for(int i = 0; i < pupils.size(); i++){
        cout << pupils[i].form << pupils[i].form_s << " " << pupils[i].sur << " " << pupils[i].name << " " << pupils[i].date << endl;
    }
    return 0;
}
