//
// Created by steve on 18-10-22.
//

/**
 * 6. 建立一棵二叉树，并输出前序、中序、后序遍历结果
 */

#include <iostream>
#include <stack>
#include <queue>

using namespace std;


struct BinTreeNode {
    char data;
    BinTreeNode *leftChild, *rightChild;

    BinTreeNode(char x, BinTreeNode *l = NULL, BinTreeNode *r = NULL) : data(x), leftChild(l),
                                                                        rightChild(r) {}
};

struct stkNode {
    BinTreeNode *ptr;
    enum {
        L, R
    } tag;

    stkNode(BinTreeNode *p) : ptr(p), tag(L) {}
};

void PreOrder(BinTreeNode *subTree) {
    if (subTree != NULL) {
        cout << subTree->data;
        PreOrder(subTree->leftChild);
        PreOrder(subTree->rightChild);
    }
}

void PreOrderNotRecursive(BinTreeNode *subTree) {
    stack<BinTreeNode *> s;
    BinTreeNode *p = subTree;
    s.push(NULL);
    while (p) {
        cout << p->data;
        if (p->rightChild)s.push(p->rightChild);
        if (p->leftChild) p = p->leftChild;
        else {
            p = s.top();
            s.pop();
        }
    }
    cout << endl;
}

void InOrder(BinTreeNode *subTree) {
    if (subTree != NULL) {
        InOrder(subTree->leftChild);
        cout << subTree->data;
        InOrder(subTree->rightChild);
    }
}

void InOrderNotRecursive(BinTreeNode *subTree) {
    BinTreeNode *cur = subTree;
    stack<BinTreeNode *> s;
    s.push(NULL);
    do {
        while (cur) {
            s.push(cur);
            cur = cur->leftChild;
        }
        cur = s.top();
        s.pop();
        if (!s.empty()) {
            cout << cur->data;
            cur = cur->rightChild;
        }
    } while (cur || !s.empty());
    cout << endl;
}

void PostOrder(BinTreeNode *subTree) {
    if (subTree != NULL) {
        PostOrder(subTree->leftChild);
        PostOrder(subTree->rightChild);
        cout << subTree->data;
    }
}

void PostOrderNotRecursive(BinTreeNode *subTree) {
    BinTreeNode *p = subTree;
    stack<stkNode> s;
    do {
        while (p) {
            stkNode w(p);
            w.tag = w.L;
            s.push(w);
            p = p->leftChild;
        }
        int continue1 = 1;
        while (continue1 && !s.empty()) {
            stkNode w = s.top();
            p = w.ptr;
            s.pop();
            switch (w.tag) {
                case w.L:
                    w.tag = w.R;
                    p = p->rightChild;
                    continue1 = 0;
                    s.push(w);
                    break;
                case w.R:
                    cout << p->data;
                    break;
            }
        }
    } while (!s.empty());
    cout << endl;
}

//构造二叉树
void makeTree(string GeneralList, BinTreeNode *&root) {
    root = new BinTreeNode(GeneralList[0]);
    queue<BinTreeNode *> q;
    q.push(root);
    for (int i = 1; i < GeneralList.length(); ++i) {
        BinTreeNode *node = q.front();
        q.pop();
        char ch = GeneralList[i];
        if (ch != '*') {
            node->leftChild = new BinTreeNode(ch);
            q.push(node->leftChild);
        }
        ch = GeneralList[++i];
        if (ch != '*') {
            node->rightChild = new BinTreeNode(ch);
            q.push(node->rightChild);
        }
    }
}

int main() {
    string genList;
    cin >> genList;
    BinTreeNode *root;
    makeTree(genList, root);
    cout << "PreOrder" << endl;
    PreOrder(root);
    cout << endl;
    PreOrderNotRecursive(root);
    cout << endl;
    cout << "InOrder" << endl;
    InOrder(root);
    cout << endl;
    InOrderNotRecursive(root);
    cout << endl;
    cout << "PostOrder" << endl;
    PostOrder(root);
    cout << endl;
    PostOrderNotRecursive(root);
    return 0;
}