#include<iostream>
#include<stack>
using namespace std;

bool isValidParenthesis(string x)
{
    stack<char> s;
    
   for(int i=0;i<x.length();i++)
   {
       char c=x[i];
       if(c=='[' || c=='{' || c=='(')
           s.push(c);
       else
       {
           if(!s.empty())
           {
               char top=s.top();
               if(top=='[' && c==']' || top=='{' && c=='}' || top=='(' && c==')')
                    s.pop();
               
               else
                   return false;
           }
           else
               return false;
       }
   }
    if(s.empty())
        return true;
    else
        return false;
}

int main()
{
    string s;
    cout<<"Entre parenthesis string to check for balanced or not"<<endl;
    cin>>s;

    if(isValidParenthesis(s))
        cout<<"valid parenthesis"<<endl;
    else
        cout<<"Not Valid parenthesis"<<endl;

    return 0;
}