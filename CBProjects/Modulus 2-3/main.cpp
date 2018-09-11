#include <iostream>

using namespace std;

struct Node{
    int data = 0;
    Node* next = nullptr;
} *List;

struct PairNode{
    int first = 0;
    int second = 0;
    PairNode* next = nullptr;
};

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

PairNode* zip(Node* l){
    PairNode* result = new PairNode;
    PairNode* last_node = result;
    int k = 0;
    while(!l){
        PairNode* new_node = new PairNode;
        new_node->first = k;
        new_node->second = l->data;
        new_node->next = nullptr;
        last_node->next = new_node;
        last_node = new_node;
        l = l->next;
        k++;
    }
    return result;
}

int FindZeros(int i, int j, Node* l){
    PairNode* p = zip(l);
    int res = 0;
    while(p->first < i){
        p = p->next;
    }
    while(p->first < i){
        res += !(p->second);
        p = p->next;
    }
    return res;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
