//
// Created by steve on 18-9-4.
//

#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;

    Node(int v) : val(v), next(NULL) {}
};

int get_linked_list_length(Node *root) {
    if (root == NULL) return 0;
    else {
        return get_linked_list_length(root->next) + 1;
    }
}

int main() {
    Node *root = new Node(0);
    root->next = new Node(1);
    cout << get_linked_list_length(root) << endl;
    cout << get_linked_list_length(NULL) << endl;
    cout << get_linked_list_length(new Node(10)) << endl;
    return 0;
}