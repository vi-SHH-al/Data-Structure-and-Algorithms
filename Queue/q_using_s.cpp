/* queue using two stack */

#include<bits/stdc++.h>
using namespace std;
class queue
{
    stack<int> s1; // main stack
    stack<int> s2;  // temp stack

    void push(int data){
        s1.push(data);
    }

    int pop(){
        // empty the s1 into s2
        while(!s1.empty()){
            s2.push(s1.top());  
            s1.pop();    
        }
        // popping the s2.top() [bottom of stack s1] i.e. front of our queuse
        int ans=s2.top();      
        s2.pop();               
        // inserting the elements in s1 in same order
        while(!s2.empty()){
            s1.push(s2.top());  
            s2.pop();         
        }                
        return ans;
    }

    int front(){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        int ans=s2.top();

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
};


int main()
{
    return 0;
}