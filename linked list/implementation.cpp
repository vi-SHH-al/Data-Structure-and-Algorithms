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
    ~Node()
    {
        next=NULL;
        delete next;
    }

};

void InsertAtHead(Node*&head, int d)
{   
    if(head==NULL)
    {
        Node* temp=new Node(d);
        head=temp;
        return;
    }
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}

void InsertAtTail(Node* &tail,int d)
{
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}

void InsertAtPosition(Node* &tail,Node* &head,int position,int n)
{
    if(position==1)         //if position is 1...so to settle the head pointer
        {                   // we simply calling the insert a head function
            InsertAtHead(head,n);
            return;
        }

    Node*temp=head;
    int cnt=1;
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }                       
                            
    if(temp->next==NULL)    // if the temp become the last node which means
    {                        // we have insert it in tail,,simply call tail function
        InsertAtTail(tail,n);
        return;
    }
    Node* nodetoinsert=new Node(n);
    nodetoinsert -> next = temp -> next;
    temp -> next = nodetoinsert;
}

void DeleteAt(int position,Node* &head,Node *&tail)
{
    if(position ==1)
    {   
        Node* temp=head;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        Node *curr=head;
        Node *prev=NULL;
        int cnt=1;
        while(cnt<position)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        // if delete at tail is called ,for updation of tail,
        //if required
        if(curr->next==NULL)
        {
            tail=prev;
        }   
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

void print(Node* head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* node1=new Node(10);
    // cout<<node1->data<<endl;
    //cout<<node1->next<<endl;
    Node*head = node1;
    Node*tail = node1;
    // if we don't have intial node,, then we will head as NULL
    InsertAtHead(head,15);
    print(head);
    
    InsertAtTail(tail,30);
    print(head);
   
    InsertAtHead(head,20);
    print(head);
    
    InsertAtPosition(tail,head,1,99);    //insert 99 at given location
    print(head);
    cout<<"delete the element at last:"<<endl;
    DeleteAt(5,head,tail);
    print(head);
    cout<<"delete the first element"<<endl;
    DeleteAt(1,head,tail);
    print(head);
    return 0;
}