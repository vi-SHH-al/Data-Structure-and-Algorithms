#include<iostream>
#include<map>
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

Node* floyd_detect(Node* head)  // we can use bool too as return type
{
    if(head==NULL)
        return NULL;
    
    Node* slow=head;
    Node* fast=head;

    while(slow!=NULL && fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
            fast=fast->next;
        
        slow=slow->next;

        if(slow==fast)
            return slow;
    }

    return NULL;
}

Node* starting_node(Node* head)
{
    if(head==NULL)
        return NULL;
    
    Node* intersection=floyd_detect(head);  // fast node
    Node* slow=head;                        // slow node back to head

    while(slow!=intersection)
    {                                   // increasing both pointer by 1 node
        slow=slow->next;            
        intersection=intersection->next;
    }           // when both our pointer is equal,that point is our starting point

    return slow;
}

bool detectloop(Node* head) //   map/flag approach
{
    if(head==NULL)
        return 0;
    
    map<Node*,bool> visited;
    Node* temp=head;

    while(temp!=NULL)
    {
        if(visited[temp]==true)
            return true;        //loop is present
                                // becasue we again go the node which is marked as 1
        visited[temp]=true;
        temp=temp->next;
    }                   
    return false;       // loop is not present
}

void insertathead(Node* &head,int n)
{   
    if(head==NULL)
    {
        Node* temp=new Node(n);
        head=temp;
        return;
    }
    Node* temp=new Node(n);
    temp->next=head;
    head=temp;
}

void insertattail(Node* head,int n)
{   if(head==NULL)
    {
        insertattail(head,n);
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    Node* newnode= new Node(n);
    temp->next=newnode;
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

void remove_loop(Node* &head)
{
    if(head==NULL)
        return ;
    
    Node *start=starting_node(head);

    Node* temp=start;

    while(temp->next!=start)
        temp=temp->next;

    temp->next=NULL;
    
}

int main()
{   Node* head=NULL;
    insertathead(head,4);
    insertathead(head,3);
    insertathead(head,2);
    insertathead(head,1);
    insertattail(head,5);
    insertattail(head,6);
    print(head);

    Node* tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    tail->next = head->next->next;
    //loop between  3-last

    if(detectloop)
        cout<<" LOOP is present checked by map or flag approach \n"; 

    if(floyd_detect(head)!=NULL)
        cout<<" LOOP is present , checked by floyd algorithm \n"; 
    
    Node* start=starting_node(head);
    cout<<" Starting node of loop  is:  "<<start->data<<endl;
    
    remove_loop(head);
    print(head);
    
    cout<<endl;
    return 0;
}