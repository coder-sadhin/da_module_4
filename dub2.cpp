#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void removeDupli(Node* head) {
    Node* c = head;

    while (c != NULL) {
        Node* a = c;
        while (a->next != NULL) {
            if (a->next->val == c->val) {
                Node* temp = a->next;
                a->next = a->next->next;
                delete temp;
            } else {
                a = a->next;
            }
        }
        c = c->next;
    }
}

void printList(Node* head) {
    Node* c = head;
    while (c != NULL) {
        cout << c->val << " ";
        c = c->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int val;

    while (cin >> val && val != -1) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    removeDupli(head);
    printList(head);

    Node* c = head;
    while (c != NULL) {
        Node* temp = c;
        c = c->next;
        delete temp;
    }

    return 0;
}