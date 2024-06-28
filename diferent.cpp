#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insertLink(Node *&head, Node *&tail, int val) {
    Node *newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void max_min(Node *head, int &minVal, int &maxVal) {
    Node *temp = head;
    minVal = INT_MAX;
    maxVal = INT_MIN;
    while (temp != NULL) {
        minVal = min(minVal, temp->val);
        maxVal = max(maxVal, temp->val);
        temp = temp->next;
    }
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    int val;

    while (cin >> val && val != -1) {
        insertLink(head, tail, val);
    }

    int mn, mx;
    max_min(head, mn, mx);

    cout << (mx - mn) << endl;

    return 0;
}