#include<bits/stdc++.h>
using namespace std;


//reverse using stack
queue<int> rev(queue<int> q)
{
    stack<int> s;
    int n=q.size();
    for(int i=0;i<n;i++)    // storing data of queue in stack
    {
        int data=q.front();
        q.pop();
        s.push(data);
    }
    for(int i=0;i<n;i++)    // reentring data form stack in queue
    {
        int data=s.top();
       q.push(data);
       s.pop();
    }
    return q;
}


//reversing using recursion
void reverse(queue<int>& q)
{
    
    if(q.empty())
        return ;
    int data=q.front();
    q.pop();
    reverse(q);
    q.push(data);
    
}


queue<int> reverse_recurssion(queue<int> q)
{   
    reverse(q);
    return q;
}