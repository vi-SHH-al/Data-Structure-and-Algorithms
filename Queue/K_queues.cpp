#include<bits/stdc++.h>
using namespace std;

class kqueue
{
    public:
        int n;
        int k;
        int *front;
        int *rear;
        int *next;
        int *arr;
        int freespot;

        kqueue(int n, int k)
        {
            this->n=n;
            this->k=k;
            front=new int(k);
            rear= new int(k);
            next= new int[n];
            arr= new int[n];

            for(int i=0;i<k;i++)
            {
                front[i]=rear[i];
                rear[i]=-1;
            }

            for(int i=0;i<n;i++)
                next[i]=i+1;
        }

        void enqueue(int data, int q)
        {
            // Checking for overflow condition 
            if(freespot == -1)
            cout<<" Overflow "<<endl;

            //finding index in which we can insert element in array
            int index = freespot;

            //Updation freespot as previous one will occupied by the new element
            freespot=next[index];

            //checking for first element
            if(front[q] == -1)
                {
                    front[q] = index;
                    rear[q] = index;
                }
            else    // for other cases
            {
                next[rear[q]]=index;    //  next of rear[q] will point to the index at which    
            }                           //new element is insered i.e. new rear

            next[index] = -1;   // indication it's not anymore free
            rear[q]=index;      // updating rear

            arr[index]= data;  // inserting data at index
        }

        int dequeue(int q)
        {
            //checkinf for underflow
            if(front[q] == -1)
                {
                    cout<<"Underflow condition ";
                    return -1;
                }
            
            //index to be popped i.e. front index
            int index = front[q];

            //Updation of  front // new fornt
            front[q] = next[index];

            //adjusting the freespot
            // making previous fornt index as freespot and linked it with the previous freespot
            //before pop
            next[index] = freespot;     //index point to freespot_1
            freespot = index;           //freespot_0 is index and it point to freespot_1

            return arr[index]; 
            
            
        }
};

int main()
{
    return 0;
}