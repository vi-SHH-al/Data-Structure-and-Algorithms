#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

class queue
{
    public:
    Node *front=NULL;
    Node *rear=NULL;

    void enqueue(int data)
    {
        if(front==NULL)
        {
            Node* new_node= new Node();
            new_node->data=data;
            new_node->next=NULL;
            front=rear=new_node;
        }
        else
        {
            Node* new_node= new Node();
            new_node->data=data;
            new_node->next=NULL;
            rear->next=new_node;
            rear=new_node;
        }
    }

    void dequeue()
    {
        if(front==NULL)
            cout<<"QUeue is empty";
        
        if(front==rear)
        {
            Node* temp=front;
            front=rear=NULL;
            delete temp;
        }
        else
        {
            Node* temp=front;
            front=front->next;
            delete temp;
        }     
    }

    void display()
    {
        Node* temp=front;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};

int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.display();
    cout<<endl;

    q.dequeue();
    q.dequeue();
    q.display();
    cout<<endl;
    return 0;
}