#include <bits/stdc++.h> 
using namespace std;
class NStack
{
public:
    
    int *arr;
    int *next;
    int *top;
    int freespot;
    
    //COnstructor
    NStack(int N, int S)
    {
        arr=new int[S];
        top= new int[N];
        next=new int[S];
        
        //intialize top as -1
        for(int i=0;i<N;i++)
            top[i]=-1;
        
        //intialize next[i] as i+1
        for(int i=0;i<S;i++)
            next[i]=i+1;
        next[S-1]=-1;
        
        freespot=0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //checking for overflow
        if(freespot == -1)
            return false;
        
        //Step-1: Find index for pushing x
        int index = freespot;
        
        //Step-2: Update the freespot, current one is used by x
        //        so point it to new free spot
        freespot = next[index];
        
        //Step-3: insert x in arr
        arr[index] = x;
        
        //Step-4 : Update next; it will point to next  element of         
        //         current stack after insertion i.e top before insertion
        next[index] = top[m-1];
        
        //Step-5: Update the top
        top[m-1] = index;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {        //here the element is not popped in real;
            //we just popping it imaginarry and override it's location when we   push 
         if(top[m-1] == -1)    //-1 indicates the stack is empty
             return -1;
        
        int index = top[m-1];//storing index of top of stack in variable index
        
        top[m-1] = next[index];    //next[index] will store the next element of stack
                                   //i.e element below top. so here we update top 
        
        next[index] = freespot;  //freespot have a value of index+1;
        //next[index] will point to index+1 if arr[index] has no elements forit, after popping stack , the arr[index] is clear for us
        
        freespot = index;    //element can store at index , so we  make it  a freespot
        
        return arr[index];    //returning the popped element
    }
};