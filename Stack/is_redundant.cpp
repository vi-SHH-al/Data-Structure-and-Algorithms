/*
Problem: 
Given a string of balanced expression, 
find if it contains a redundant parenthesis or not.0
A set of parenthesis are redundant
if the same sub-expression is surrounded by unnecessary or multiple brackets.
return true if redundant, else false.
*/

//Logic: if there is no operator between the corresponding open and close bracket 
// then the string is redundant
#include <bits/stdc++.h> 
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> stack;
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        
        if(ch=='(' || ch=='*' || ch=='/' || ch=='-' || ch=='+' )
        {
            stack.push(ch);
        }
        else
        {      
            // if ch is '(' or alphabets
            if(ch==')')
            {
                bool redundant=true;

                while(stack.top()!='(')
                {
                    if(stack.top()=='*' || stack.top()=='/' || stack.top()=='-' || stack.top()=='+' )
                    {   //if operator is present before ( , then it's not redundant
                        redundant=false;
                        stack.pop();
                    }
                    
                }

                //redundant=true, if while loop is over and no operator is found till ')'.
                if(redundant==true)
                {
                    return true;
                }
                //we pop the '('  from the stack after the loop(popping out element above'(' )
                stack.pop();
            }           
        }
    }
    return false;
}
