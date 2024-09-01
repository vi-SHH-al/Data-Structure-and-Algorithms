/*
Given a string S consisting of only opening and closing curly brackets '{' and '}',
find out the min no. of reversals required to convert the string into a balanced expression
A reversal means changing '{' to '}' or vice-versa.
*/

#include <bits/stdc++.h> 
using namespace std;

int findMinimumCost(string str) {
  // Write your code here
    
    if(str.length() & 1)
         return -1;
    
    stack<char> s;
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        
        if(ch=='{')
            s.push(ch);
        else
        {
            if(!s.empty() &&  s.top()=='{')
                s.pop();
            else
                s.push(ch);
        }
    }
    int a=0,b=0;
    while(!s.empty())
    {
        if(s.top()=='{')
            a++;
        else
            b++;
        s.pop();
    }
    return (a+1)/2 + (b+1)/2;
    
}