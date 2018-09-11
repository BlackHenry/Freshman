#include <iostream>

using namespace std;

struct Date{
    int year;
    int month;
    int day;
};

struct Node{
    Date data;
    Node* next;
};

void print(Node* l, bool debug = 0){
    while(l){
        cout << l->data.year << " " << l->data.month << " " << l->data.day << endl;
        if(debug)
            cout << l->next << endl;
        l = l->next;
    }
    cout << endl;
}

Node* add(Node* l, int y, int m, int d){
    Node* new_node = new Node;
    Node* first = l;
    new_node->next = nullptr;
    Date date;
    date.year = y;
    date.month = m;
    date.day = d;
    new_node->data = date;
    if(l == nullptr){
        return new_node;
    }
    while(l->next != nullptr){
        l = l->next;
    }
    l->next = new_node;
    return first;
}

int main()
{
    Node* List = nullptr;
    List = add(List, 2000, 12, 30);
    print(List, 1);
    List = add(List, 2001, 11, 20);
    print(List, 1);
    List = add(List, 2002, 8, 25);
    print(List, 1);
    List = add(List, 2003, 5, 11);
    print(List, 1);
    Node* temp = List;
    temp = temp->next;
    temp->next = temp->next->next;
    print(List, 1);
    return 0;
}
