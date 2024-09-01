#include<iostream>
using namespace std;
class Node
{   
    public:
    int data;
    Node* next;
    Node* arb;

    Node(int d)
    {
        data=d;
        next=NULL;
        arb=NULL;
    }
};

class Solution
{   //Approac1:
    // TC: O(N)
    // SC: O(N)-- Map space
    
    /*
    void insertattail(Node* &head,Node* &tail,int d)
    {   Node* temp=new Node(d);
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }
    public:
    Node *copyList_map(Node *head)
    {    
        Node* Chead=NULL;
        Node* Ctail=NULL;
        
        //creating a clone node
        
        Node* temp=head;
        
        while(temp!=NULL)
        {
            insertattail(Chead,Ctail,temp->data);
            temp=temp->next;
        }
        
        //Creating a map to map the original and clone node elements
        //we will access random pointer for clone node from its corresponding
        //mapped original node
        
        map<Node*, Node*> oldtonewNode;
        Node* original=head;
        Node* clown=Chead;
        while(original != NULL)
        {
            oldtonewNode[original]=clown;
            original=original->next;
            clown=clown->next;
        }
        
        original=head;
        clown=Chead;
        
        while(original!=NULL)
        {
            clown->arb=oldtonewNode[original->arb];
            // original ->arb is random pointer of original and it's mapped value is it's
            //corresponding clown value;
            original=original->next;
            clown=clown->next;
        }
        
        return Chead;
    }
    */
    public:
    Node *copyList(Node *head)
    {
    Node* curr=head;
    //Node* temp=NULL;
    //inserting new nodes in the given list.
    while(curr!=NULL)
    {
       Node* temp=new Node(curr->data);
       temp->next=curr->next;
       curr->next=temp;
       curr=temp->next;
    }
    
    //assigning arb pointers of new nodes
    curr=head;
    while(curr!=NULL)
    {   if(curr->arb!=NULL)
            curr->next->arb=curr->arb->next;
        else
            curr->next->arb=curr->arb;
        curr=curr->next->next;
    }
    
    Node* original=head;
    Node* clone=head->next;
    Node* clonehead=clone;
    
    while(original!=NULL)
    {
        original->next=original->next->next;
        if(clone->next!=NULL)
            clone->next=clone->next->next;
        original=original->next;
        clone=clone->next;
    }
    return clonehead;
    }
};