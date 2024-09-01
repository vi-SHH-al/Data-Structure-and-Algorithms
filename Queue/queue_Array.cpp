    #include<iostream>
    using namespace std;
    class queue
    {
        int front;
        int rear;
        int *arr;
        int size;

        queue(int size)
        {   
            this->size = size;
            arr=new int(size);
            rear= -1;
            front= -1;
        }

        ~queue()
        { 
            delete []arr;
        }

        void enqueue(int data)
        {
            if(rear== size-1)
                cout<<" Queue is full "<<endl;
            else 
                if(front== -1 && rear == -1)
                {
                    front=rear=0;
                    arr[rear]=data;
                }
                else
                {   
                    rear++;
                    arr[rear] = data;  
                }
        }

        void dequeue()
        {
            if(front ==-1 && rear == -1)  
            {
                cout<<" Queue is empty"<<endl;
                return;
            }

            if(front == rear)   // single element left
            {
                cout<<"Last element is popped"<<arr[front];
                front = rear = -1;      
            }
            else
            {
                cout<<"Popped element is :  "<<arr[front]<<endl;  
                front++;
            }
        }

        void display()
        {
            if(front == -1 && front == -1)
                cout<<" Queue is empty";

            int i=front;
            while(i <= rear )
            {
                cout<<"  "<<arr[i];
                i++;
            }
        }

        int front_element()
        {
            if(front == -1 )
                return -1;
            else
                return arr[front];
        }
    };
    int main()
    {   

        return 0;
    }