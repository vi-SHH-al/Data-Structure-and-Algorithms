#include <bits/stdc++.h> 
using namespace std;

void sorted_insert(stack<int> &stack,int temp)
{
    if(stack.empty() || stack.top()<temp)
    {
        stack.push(temp);
        return;
    }
    
    int n=stack.top();
    stack.pop();
    
    sorted_insert(stack,temp);
    
    stack.push(n);
}

void sortStack(stack<int> &stack)
{
    if(stack.empty())
         return;
   
    int temp=stack.top();
    stack.pop();
    
    sortStack(stack);
    
    sorted_insert(stack,temp);
}