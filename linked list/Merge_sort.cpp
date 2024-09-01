#include<iostream>
using namespace std;

class node
{   public:
    int data;
    node* next;

    node(int n)
    {
        data=n;
        next=NULL;
    }
};

node* findmid(node* head)
{    
    if(head==NULL||head->next==NULL||head->next->next==NULL)
        return head;
    
    node* slow=head;
    node* fast=head;
    
    while(fast!=NULL && fast->next!=NULL)
    {
       slow=slow->next;
       fast=fast->next->next;
    }
    return slow;
}

node* merge(node* left, node* right)
{
    if(left==NULL)
        return right;
    if(right==NULL)
        return left;
        
    node* ans=new node(-1);
    node* temp=ans;
    
    //merging 2 sorted linked list
    while(left!=NULL && right!=NULL)
    {
        if(left->data <= right->data)
        {
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else
        {
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }
    
    while(left!=NULL)
    {
        temp->next=left;
        temp=left;
        left=left->next;
    }
    
    while(right!=NULL)
    {
        temp->next=right;
        temp=right;
        right=right->next;
    }
    
    return ans->next;
}

node* mergeSort(node *head) 
{
    // Write your code here
    
    //base condtion.
    if(head==NULL||head->next==NULL)
        return head;
    
    //dividing the list in left part and right part
    node* mid=findmid(head);
    node* left=head;
    node* right=mid->next;
    mid->next=NULL;
    
    //recurrsively sorting the left and right part
    left=mergeSort(left);
    right=mergeSort(right);
    
    //merging the linked list
    node* result=merge(left,right);
    
    return result;
    
}
