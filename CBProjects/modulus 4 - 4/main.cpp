#include <iostream>

using namespace std;

struct BinaryTreeNode{
    int data;
    BinaryTreeNode *left = nullptr, *right = nullptr, *parent = nullptr;
} *leftTree, *rightTree;

int k;

BinaryTreeNode* insertBinaryTree(BinaryTreeNode *where, int what){
    BinaryTreeNode *insertion = new BinaryTreeNode;
    insertion->data = what;
    if(!where)
        return insertion;
    BinaryTreeNode *temp = where;
    BinaryTreeNode *old_temp = temp;
    while(temp){
    *old_temp = temp;
        if (temp->data < insertion->data){
            temp = temp->right;
            continue;
        }
        temp = temp->left;
    }
    temp = old_temp;
    if(insertion->data > temp->data){
        temp->right = insertion;
    }
    else{
        temp->left = insertion;
    }
    return where;
}

void Split(BinaryTreeNode *tree){
    if(!tree){
        return;
    }
    if(tree->data >= k){
        rightTree = insertBinaryTree(rightTree, tree->data);
    }
    else{
        leftTree = insertBinaryTree(leftTree, tree->data);
    }
    Split(tree->left);
    Split(tree->right);
}

void PrintTree(BinaryTreeNode *tree){
    if(!tree)
        return;
    cout << tree->data << " ";
    PrintTree(tree->left);
    PrintTree(tree->right);
}

int main()
{
    BinaryTreeNode *bt = new BinaryTreeNode;
    BinaryTreeNode *left = new BinaryTreeNode;
    BinaryTreeNode *right = new BinaryTreeNode;
    BinaryTreeNode *left1 = new BinaryTreeNode;
    BinaryTreeNode *right1 = new BinaryTreeNode;
    BinaryTreeNode *left2 = new BinaryTreeNode;
    BinaryTreeNode *right2 = new BinaryTreeNode;

    left1->data = 1;
    left2->data = 4;
    left->data = 2;
    left->left = left1;
    left->right = left2;

    right1->data = 6;
    right2->data = 8;
    right->data = 7;
    right->left = right1;
    right->right = right2;

    bt->data = 5;
    bt->left = left;
    bt->right = right;

    cin >> k;
    Split(bt);
    PrintTree(leftTree);
    cout << "\n\n\n";
    PrintTree(rightTree);
    return 0;
}
