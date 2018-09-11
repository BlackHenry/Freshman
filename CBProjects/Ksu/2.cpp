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

// Реалізована функція:
Node* add_to_last_date(Node* l, int y, int m, int d){
    Node* temp = l;
    int i = 0, k = 0, min_year = 10000, min_month = 13, max_day = 0;
    while(temp){
        if(temp->data.year <= min_year && temp->data.month <= min_month && temp->data.day > max_day){
            i = k;
            min_year = temp->data.year;
            min_month = temp->data.maonth;
            max_day = temp->data.day;
        }
        k++;
        temp = temp->next;
    }
    temp = l;
    for (int j = 1; j < i; j++){
        temp = temp->next;
    }
    Node* new_node = new Node;
    new_node->next = temp->next;
    new_node->data.year = y;
    new_node->data.month = m;
    new_node->data.day = d;
    temp->next = new_node;
    return l;
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
