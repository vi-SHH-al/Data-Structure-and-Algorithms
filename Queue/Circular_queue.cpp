#include <bits/stdc++.h> 
class CircularQueue{
    public:
    int front;
    int rear;
    int *arr;
    int size;
    // Initialize your data structure.
    CircularQueue(int n){
       arr=new int[n];
        front=rear=-1;
        size=n;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value)
    {
        if((front==0 && rear ==size-1)  ||( front!=0 && rear==(front-1)%(size-1)) )
            return false;// queue is full
        else
            if(front==-1)   //empty queue
            {               //inserting first element
                front=rear=0;
                arr[rear]=value;
            }
            else    //we can use rear= (rear+1)%size instead of below code...
                if(rear == size-1 ) // if rear is at end
                {  //here front is !=0 else queue is full, we take this cond.  at start of function
                    rear=0;         //manataiong circular cycle
                    arr[rear]=value;
                }
                else        // rear in the middle and queue is not full and front - x
                {
                    rear++;
                    arr[rear]=value;
                }
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
       if(front==-1)        //underflow condition
           return -1;
        
       int ans=arr[front];      // storing the pop element
       arr[front]=-1;
       
        if(front==rear)         // single element
            front=rear=-1;
        else 
            if(front==size-1)     //front is at the end of queue. so after popping in end
                front=0;          //it will go to the start due to cycle
            else
                front++;        //front is in middle
        return ans;
    }
};