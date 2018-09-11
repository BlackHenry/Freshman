#include <iostream>

using namespace std;

struct Node{
    int data = 0;
    Node* next = nullptr;
};

struct NodeNode{
    Node* = nullptr;
    NodeNode* next;
} List;

Node* add(Node* l, int d){
    Node* new_node = new Node;
    Node* first = l;
    new_node->next = nullptr;
    new_node->data = d;
    if(l == nullptr){
        return new_node;
    }
    while(l->next != nullptr){
        l = l->next;
    }
    l->next = new_node;
    return first;
}

Node* add(NodeNode* l, int d){
    Node* new_node = new Node;
    Node* first = l;
    new_node->next = nullptr;
    new_node->data = d;
    while(l->data->data % 10 != d % 10){
        l = l->next;
    }
    l->data = add(l->data, d);
    return first;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
