#include<iostream>
#include<stack>
using namespace std;
/*
    popping element one by one and storing it in data varaible
    and whem we reach the midde i.e. size/2;
    pop the topmostelement i.e. middle of original stack
    and start returning the calls
    after each call we push the element that we popped previously

*/
void del(stack<int>&Stack,int count, int size)
{
    if(count==size/2)
    {
        Stack.pop();
        return;
    }
    int data=Stack.top();
    Stack.pop();
    
    del(Stack,count+1,size);
    Stack.push(data);

}
void deleteMiddle(stack<int>&inputStack, int N){
	
    int count=0;
    del(inputStack,count,N);
   
}