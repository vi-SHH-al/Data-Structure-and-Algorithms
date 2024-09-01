

#include<iostream>
using namespace std;
class Node{
    public:
    Node* prev;
    int data;
    Node* next;

    //constructor
    Node(int d)
    {
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
};
//bu declaring Head and Tail globallt we can
//free from passing it in every function
// Node* HEAD=NULL;
// Node* TAIL=NULL;

Node* reverse(Node* head)
{
    Node* back=NULL;
    Node* curr=head;
    Node* forward=NULL;

    while(curr!=NULL)
    {
        forward=curr->next;
        curr->next=curr->prev;
        curr->prev=forward;
       // back->next=back->prev;
        //back->prev=curr;
        back=curr;
        curr=forward;
    }
    return back;
}
void print(Node* head)
{  
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int length(Node* head)
{   int l=0;
    Node* temp= head;
    while(temp!=NULL)
    {
        l++;
        temp=temp->next;
    } 
    return l;
}

void InsertAtHead(Node* &head,Node* &tail,int n)
{   
    if(head==NULL)
    {
        Node* temp= new Node(n);
        temp->next=NULL;
        temp->prev=NULL;
        head=temp;
        tail=temp;
    }
    else
    {
    Node* temp= new Node(n);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
}

void InsertAtTail(Node* &head,Node* &tail,int n)
{
    if(tail==0)
    {
        Node* temp=new Node(n);
        temp->prev=NULL;
        temp->next=NULL;
        tail=temp;
        head=temp;
    }
    else
    {
        Node* temp=new Node(n);
        temp->prev=tail;
        tail->next=temp;
        tail=temp;
    }
}

void InsertAtPosition(Node* &head,Node*&tail,int position,int n)
{
    if(position==1)
    {
        InsertAtHead(head,tail,n);
        return;
    }

    Node* temp=head;
    int cnt=1;
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }

    if(temp->next==NULL)
    {
        InsertAtTail(head,tail,n);
        return;
    }

    Node* nodetoinsert=new Node(n);

    nodetoinsert->next=temp->next;
    temp->next->prev=nodetoinsert;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;
}

void DeleteAtPosition(Node* &head,Node* &tail,int position)
{   //checking for head deletion
    if(position==1)
    {
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;    
    }
    else    // tail and middle case
    {
        Node* curr=head;
        Node* prev = NULL;

        int cnt=1;

        while(cnt<position)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        //for tail deletion (to adjust the tail)
        if(curr->next==NULL)
        {
            tail=prev;
            prev->next=curr->next;  // null
            curr->prev=NULL;
            delete curr;
            return ;
        }
        // below case only execute when positoin is not head or tail
        // here only 1 step is neglected in the tail block
        curr->next->prev=curr->prev;
        prev->next=curr->next;
        curr->next=NULL;
        curr->prev=NULL;

        delete curr;
    }

}

int main()
{
    //Node *node1=new Node(10);
    Node *head=NULL;
    Node *tail=NULL;
    // cout<<"Lenght = "<<length(head)<<endl;
    // print(head);

    InsertAtPosition(head,tail,1,10);
    print(head);

    InsertAtHead(head,tail,22);
    print(head);

    InsertAtHead(head,tail,20);
    print(head);

    InsertAtTail(head,tail,12);
    print(head);

    InsertAtPosition(head,tail,4,100);
    print(head);

    DeleteAtPosition(head,tail,5);
    print(head);

    Node* rehead=reverse(head);
    print(rehead);
    return 0;
}