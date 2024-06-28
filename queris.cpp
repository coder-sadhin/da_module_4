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
void insert_at_tail(Node *&head, int v)
{
    Node *newNode = new Node(v);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}
void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}
void insert_at_head(Node *&head, int v)
{
    Node *newNode = new Node(v);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}
void delete_from_position(Node *head, int pos)
{
    if (head == NULL)
    {
        return;
    }
    Node *tmp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        tmp = tmp->next;
        if (tmp == NULL)
        {
            return;
        }
    }
    if (tmp->next == NULL)
    {
        return;
    }
    Node *deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    delete deleteNode;
}
void delete_head(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    Node *deleteNode = head;
    head = head->next;
    delete deleteNode;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    Node *head = NULL;
    while (n--)
    {
        int op,val;
        cin >> op >> val;
        if(op == 0){
            insert_at_head(head, val);
            print_linked_list(head);
        }
        else if (op == 1)
        {
            insert_at_tail(head, val);
            print_linked_list(head);
        }
        else if(op == 2){
            if(val==0){
                delete_head(head);
            }
            else{
                delete_from_position(head, val);
            }
            print_linked_list(head);
        }
        else
        {
            print_linked_list(head);
        }
        
        cout<<endl;
    }
    return 0;
}