#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // Node(int data)
    // {
    //     this->data=data;
    //     next=NULL;
    // }
};

class stack{
    public:
    Node* top=NULL;

    void push(int data)
    {
        Node* new_node=new Node();
        new_node->data=data;
        new_node->next=top;
        top=new_node;
    }

    void pop()
    {
        if(top==NULL)
            cout<<"Stack underflow"<<endl;
        else
        {
            Node* temp=top;
            top=top->next;
            delete temp;
        }
    }

    void peek()
    {
        if(top==NULL)
            cout<<" Stack is empty"<<endl;
        else
        {
            cout<<"TOpped element is : "<<top->data<<endl;
        }
    }

    bool empty()
    {
        if(top==NULL)
            return 1;
        else
            return 0;
    }

    void display()
    {
        if(top==NULL)
            cout<<"Stack is empty"<<endl;
        else
        {
            Node* temp=top;
            cout<<" Elements from top-> bottom"<<endl;
            while(temp!=NULL)
            {
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }
    }    
};

int main()
{
    stack s;
    s.push(9);
    s.push(8);
    s.push(7);
    s.push(5);
    s.push(1);
    s.push(0);

    s.display();

    s.peek();
    
    s.pop();
    s.pop();
    s.pop();

    s.display();
    s.pop();
    s.pop();
    s.pop();

    s.display();
    s.pop();

    return 0;
}