#include <iostream>
#include <list>

using namespace std;

list<int> global;

void list_union_rec(list<int> a, list<int> b){
    if (!a.size()){
        global.insert(global.end(), b.begin(), b.end());
        return
    }
    if (!b.size()){
        global.insert(global.end(), a.begin(), a.end());
        return
    }
    if(a.front() < b.front()){
        global.push_back(a.front());
        a.pop_front();
    }
    if(a.front() > b.front()){
        global.push_back(b.front());
        b.pop_front();
    }
    if(a.front() == b.front()){
        global.push_back(b.front());
        a.pop_front();
        b.pop_front();
    }
    return list_union_rec(a, b);
}

list<int> list_union(list<int> a, list<int> b){
    list<int> res;
    while(a.size() && b.size()){
        if(a.front() < b.front()){
            res.push_back(a.front());
            a.pop_front();
        }
        if(a.front() > b.front()){
            res.push_back(b.front());
            b.pop_front();
        }
        if(a.front() == b.front()){
            res.push_back(b.front());
            a.pop_front();
            b.pop_front();
        }
    }
    if(a.size()){
        res.insert(res.end(), a.begin(), a.end());
    }
    if(b.size()){
        res.insert(res.end(), b.begin(), b.end());
    }
    return res;
}

list<int> list_intersection(list<int> a, list<int> b){
    list<int> res;
    while(a.size() && b.size()){
        if(a.front() < b.front()){
            a.pop_front();
        }
        if(a.front() > b.front()){
            b.pop_front();
        }
        if(a.front() == b.front()){
            res.push_back(b.front());
            a.pop_front();
            b.pop_front();
        }
    }
    return res;
}

int main()
{
    list<int> a = {1, 2, 4, 5, 6, 10};
    list<int> b = {2, 3, 5, 7, 8};
    list<int> c = list_union(a, b);
    for(auto it: c){
        cout << it << " ";
    }
    cout << endl;
    list<int> d = list_intersection(a, b);
    for(auto it: d){
        cout << it << " ";
    }
    return 0;
}
