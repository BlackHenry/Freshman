#include <iostream>

using namespace std;

struct Node{
    int data = 0;
    Node* next = nullptr;
} *List;

Node* add(Node* l, int d){
    Node* new_node = new Node;
    Node* first = l;
    new_node->next = l;
    new_node->data = d;
    if(l == nullptr){
        new_node->next = new_node;
        l = new_node;
        return l;
    }
    while(l->next != first){
        l = l->next;
    }
    l->next = new_node;
    return first;
}

Node* reverse(Node* l){
    Node* first = l;
    l = l->next;
    Node* old_node = first;
    while(l != first){
        Node* new_node = new Node;
        new_node->next = old_node;
        new_node->data = l->data;
        old_node = new_node;
        l = l->next;
    }
    first->next = old_node;
    return old_node;
}

int main(){
    List = add(List, 1);
    List = add(List, 2);
    List = add(List, 5);
    List = add(List, 4);
    int k = 1;
    Node* temp = List;
    while(temp != List || k == 1){
        k--;
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
    k = 1;
    Node* reversed_list = reverse(List);
    temp = reversed_list;
    while(temp != reversed_list || k == 1){
        k--;
        cout << temp->data << endl;
        temp = temp->next;
    }
    return 0;
}
