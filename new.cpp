#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
    Node* head;
    Node* tail;

public:
    LinkedList() : head(NULL), tail(NULL) {}

    void addNode(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int findIndex(int a) {
        int index = 0;
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == a) {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }

    void deleteList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = NULL;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        LinkedList list;
        int value;

        while (cin >> value && value != -1) {
            list.addNode(value);
        }
        int X;
        cin >> X;

        cout << list.findIndex(X) << endl;

        list.deleteList();
    }
    return 0;
}