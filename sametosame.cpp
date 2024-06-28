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


bool check(Node* head, Node* head2) {
    Node* temp = head;
    Node* temp2 = head2;
    bool flage=true;
    while (true) {
        if (temp->val != temp2->val) {
            flage=false;
            break;
        }
        else{
            if(temp->next == NULL && temp2->next == NULL){
                break;
            }
            else if(temp->next == NULL || temp2->next == NULL){
                flage=false;
                break;
            }
            else{
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
    }
    return flage;
}

int main() {
        Node *head = NULL;
        Node *tail = NULL;
        int val;
        
        while (cin >> val && val != -1) {
            insertLink(head,tail,val);
        }
        
        Node *head2 = NULL;
        Node *tail2 = NULL;
        while (cin >> val && val != -1) {
            insertLink(head2,tail2,val);
        }

        bool ans=check(head,head2);
        if(ans){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    return 0;
}