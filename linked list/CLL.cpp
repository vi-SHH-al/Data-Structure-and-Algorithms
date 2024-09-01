#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node(int n)
    {
        data=n;
        next=NULL;
    }
};

void insertathead(Node* &head,int n)
{   
    Node* node=new Node(n);
    if(head==NULL)
    {
        node->next=node;
        head=node;
        return;
    }
    
    Node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next; 
    } 
    temp->next=node;
    node->next=head;
    head=node;

}
void insertattail(Node* &head,int n)
{   
    Node* node= new Node(n);
    if(head==NULL)
    {
        node->next=node;
        head=node;
        return;
    }   
    
    Node* temp=head;

    while(temp->next!=head)
    {
        temp=temp->next; 
    } 
    temp->next=node;
    node->next=head;

}
void insert(Node* &head,int element,int n)
{   // empty list case
    if(head==NULL)
    {
        Node *temp=new Node(n);
        head=temp;
        temp->next=temp;
    }
    else
    {
        //non-empty list
        //assiming the element is present 
        Node *curr=head;
        while(curr->data!=element)
        {
            curr=curr->next;
        }
        
        //element found and curr is representing the elment
        Node *temp=new Node(n);
        temp->next=curr->next;
        curr->next=temp;
    }
}

void deleteatpos(Node* &head,int pos)
{
    if(pos==1)//fordeletion at head
    {   Node* temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;    //reaching the tail node
        }
        Node* todelete=head;
        temp->next=head->next;
        head=head->next;    //adjusting the head
        todelete->next=NULL;
        delete todelete;    //deleting the first node

        return;
    }
    
    Node* curr=head;
    Node* prev=NULL;
    int cnt=1;
    while(cnt<pos)
    {
        prev=curr;
        curr=curr->next;
        cnt++;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
}
void print(Node* &head){
 
    Node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=head);
    cout<<endl<<"head is : "<<head->data<<endl;
    
}

int main()
{
    Node* head=NULL;
    insert(head,3,2);
    print(head);

    insert(head,2,3);
    print(head);

    insert(head,3,4);
    print(head);

    insert(head,2,5);
    print(head);

    insertathead(head,10);
    print(head);

    insertathead(head,50);
    print(head);

    insertattail(head,100);
    print(head);
    insertathead(head,1);
    print(head);

    deleteatpos(head,3);
    print(head);
    return 0;
}