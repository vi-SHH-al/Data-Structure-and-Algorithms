#include<iostream>
using namespace std;

class stack
{
    public:
    int *arr;
    int top;
    int size;

    //constructor
    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;

    }

    void push(int data)
    {
        if(top < size-1)
        {
            top++;
            arr[top]=data;
        }
        else
            cout<<" Stack overflow"<<endl;
    }

    void pop()
    {
        if(top == -1)
            cout<<" Stack underflow"<<endl;
        else
        {
            cout<<"Popped element is: "<<arr[top]<<endl;
            top--;
        }
    }

    void peek()
    {
        if(top == -1)
        {
            cout<<" Stack is empty"<<endl;;
        }
        else
        {
            cout<<" Peek is : "<<arr[top]<<endl;
        }
    }

    bool empty()
    {
        if(top == -1)
            return true;
        else
            return false;
    }
};

int main()
{

    stack s(5);
    s.push(9);
    s.push(8);
    s.push(7);
    s.push(5);
    s.push(1);
    s.push(0);

    s.peek();
    s.pop();

    s.peek();
    s.pop();

    s.peek();
    s.pop();

    if(s.empty())
        cout<<" stack is empty"<<endl;
    else
        s.peek();
        
    return 0;
}