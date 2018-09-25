//
// Created by steve on 18-9-25.
//

#include <iostream>

using namespace std;

struct Node {
    int power, modulus;//幂数,系数
    struct Node *next;

    Node(int p, int m) : power(p), modulus(m), next(NULL) {};
};

void print_exp(Node *head);

Node *add(Node *exp1, Node *exp2) {
    //假设exp1和exp2的顺序是排好的,且幂数降序排列
    Node *node = new Node(0, 0);
    Node *head = node;//结果链表的头指针
    while (exp1 || exp2) {//exp1和exp2均为NULL时退出
        if (exp1 == NULL)
            while (exp2) {
                Node *temp = new Node(exp2->power, exp2->modulus);
                node->next = temp;
                node = temp;
                exp2 = exp2->next;
            }
        else if (exp2 == NULL) {
            while (exp1) {
                Node *temp = new Node(exp1->power, exp1->modulus);
                node->next = temp;
                node = temp;
                exp1 = exp1->next;
            }
        } else if (exp1->power < exp2->power) {
            Node *temp = new Node(exp2->power, exp2->modulus);
            node->next = temp;
            node = temp;
            exp2 = exp2->next;
        } else if (exp1->power > exp2->power) {
            Node *temp = new Node(exp1->power, exp1->modulus);
            node->next = temp;
            node = temp;
            exp1 = exp1->next;
        } else {
            Node *temp = new Node(exp1->power, exp1->modulus + exp2->modulus);
            node->next = temp;
            node = temp;
            exp1 = exp1->next;
            exp2 = exp2->next;
        }
    }
    return head->next;
}

int main() {
    Node *node1 = new Node(3,1);
    node1->next = new Node(2,5);
    node1->next->next = new Node(0,9);
    Node *node2 = new Node(3,2);
    node2->next = new Node(1,8);
    node2->next->next = new Node(0,2);
    Node *head = add(node1,node2);
    print_exp(node1);
    print_exp(node2);
    print_exp(head);
    return 0;
}

void print_exp(Node *head) {
    while (head){
        cout << head->modulus << "x^"<<head->power;
        if (head->next) cout << " + ";
        else cout << endl;
        head = head->next;
    }
}