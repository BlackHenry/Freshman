#include <iostream>

using namespace std;

struct BinaryTreeNode{
    int data;
    BinaryTreeNode *left = nullptr, *right = nullptr;
};

int MaxBinaryTreeElement(BinaryTreeNode *binaryTree){
    if (!binaryTree)
        return -1e9;
    return max(max(MaxBinaryTreeElement(binaryTree->left), MaxBinaryTreeElement(binaryTree->right)), binaryTree->data);
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

    left1->data = 6;
    left2->data = 9;
    left->data = 10;
    left->left = left1;
    left->right = left2;

    right1->data = 3;
    right2->data = 0;
    right->data = 14;
    right->left = right1;
    right->right = right2;

    bt->data = 1;
    bt->left = left;
    bt->right = right;

    cout << MaxBinaryTreeElement(bt) << endl;
    return 0;
}
