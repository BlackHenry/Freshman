#include <iostream>

using namespace std;

struct BinaryTreeNode{
    int data;
    BinaryTreeNode *left = nullptr, *right = nullptr;
};

int ClosestBigger(BinaryTreeNode *binaryTree, int a){
    int result = 1e9;
    int oldData = 0;
    while (binaryTree){
        oldData = binaryTree->data;
        if (binaryTree->data <= a){
            binaryTree = binaryTree->right;
            continue;
        }
        if (binaryTree->data > a){
            result = binaryTree->data;
            binaryTree = binaryTree->left;
        }
    }
    if(oldData > a)
        return min(result, oldData);
    return result;
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

    cout << ClosestBigger(bt, 3) << endl;
    return 0;
}
