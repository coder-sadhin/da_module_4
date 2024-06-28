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


int index(Node* head, int a) {
    int index = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->val == a) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

int main() {

    int T;
    cin >> T;
    while (T--) {
        Node *head = NULL;
        Node *tail = NULL;
        int val;
        
        while (cin >> val && val != -1) {
            insertLink(head,tail,val);
        }
        int v;
        cin >> v;
        
        cout << index(head, v) << endl;
    }
    return 0;
}