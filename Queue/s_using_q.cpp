#include<bits/stdc++.h>
using namespace std;
class stack
{
    queue<int> q1;
    queue<int> q2;
    /*
        for push:
        empty the q1 into q2
        now push the new no. in empty q1  [new no. will be at the front i.e. top of stack ] 
        restore the value of q1 form q2 
    */
    void push(int data){
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(data);

        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    // popped the front element
    void pop(){
        
        q1.pop();
    }
};