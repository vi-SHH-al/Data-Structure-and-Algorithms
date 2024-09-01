#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    
    Node(int d)     //construtor for storing the value in nodes
    {
        this->data=d;
        this->next=NULL;
    }
};

Node* mergeTwoLists(Node* head1, Node* head2) 
{
        
    Node* p1=head1;
    Node* p2=head2;
    Node* dummynode =new Node(-1);
    Node* p3=dummynode;
        
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data <= p2->data)
        {
            p3->next=p1;
            p1=p1->next;
            p3=p3->next;
        }

        else
        {
            p3->next=p2;
            p2=p2->next;
            p3=p3->next;
        }
    }
    
    if(p1!=NULL)
        p3->next=p1;
    if(p2!=NULL)
        p3->next=p2;
    
    return dummynode->next;
}

Node* merge_recurssive(Node* head1,Node* head2)
{
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    
    Node* result=NULL;
    if(head1->data < head2->data)
    {
        result=head1;
        result->next=merge_recurssive(head1->next,head2);
    }
    else
    {
        result=head2;
        result->next=merge_recurssive(head1,head2->next);
    }
    return result;

}

int main()
{
    return 0;
}