#include<iostream>
using namespace std;

class Node
{   public:
    int data;
    Node* next;

    Node(int d)
    {
        data=d;
        next=NULL;
    }
};

Node* reverse_iteration(Node* head)
{
    if(head==NULL||head->next==NULL)
        return head;

    Node* curr=head;
    Node* prev=NULL;
    Node* forward=NULL;

    while(curr!=NULL)
    {
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

Node* reverse_recurssion(Node* head)
{
    if(head==NULL||head->next==NULL)
        return head;

    Node* newnode=reverse_recurssion(head->next);
    head->next->next=head;
    head->next=NULL;

    return newnode;
}
void print(Node* head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl<<endl;
}

int main()
{   cout<<endl<<endl;
    Node* node1=new Node(10);
    Node* node2=new Node(20);
    Node* node3=new Node(30);
    Node* node4=new Node(40);

    node1->next=node2;
    node2->next=node3;
    node3->next=node4;

    Node* head=node1;
    print(head);

    // Node* revhead=reverse_iteration(head);
    // print(revhead);
    
    Node* revhead1=reverse_recurssion(head);
    print(revhead1);
    return 0;
}