//
// Created by steve on 18-10-22.
//

/**
 * 6. 建立一棵二叉树，并输出前序、中序、后序遍历结果
 */

#include <iostream>
#include <stack>

using namespace std;

struct BinTreeNode {
    char data;
    BinTreeNode *leftChild, *rightChild;

    BinTreeNode(char x, BinTreeNode *l = NULL, BinTreeNode *r = NULL) : data(x), leftChild(l),
                                                                        rightChild(r) {}
};

void PreOrder(BinTreeNode *subTree) {
    if (subTree != NULL) {
        cout << subTree->data;
        PreOrder(subTree->leftChild);
        PreOrder(subTree->rightChild);
    }
}

void InOrder(BinTreeNode *subTree) {
    if (subTree != NULL) {
        InOrder(subTree->leftChild);
        cout << subTree->data;
        InOrder(subTree->rightChild);
    }
}

void PostOrder(BinTreeNode *subTree) {
    if (subTree != NULL) {
        PostOrder(subTree->leftChild);
        PostOrder(subTree->rightChild);
        cout << subTree->data;
    }
}

BinTreeNode *makeTree(BinTreeNode *&root, char *GeneralList) {
    //通过广义表来构建二叉树
    char ch = GeneralList[0];
    GeneralList++;

    return root;
}

int main() {
    string genList;
    cin >> genList;
    BinTreeNode *root;
    makeTree(root, &(genList[0]));
    PreOrder(root);
    cout << endl;
    InOrder(root);
    cout << endl;
    PostOrder(root);
    return 0;
}