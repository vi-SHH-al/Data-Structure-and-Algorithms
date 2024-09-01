#include<iostream>
using namespace std;
//finding lenth of string
int len(char s1[100])
{ 
int l=0;
for(int i=0;;i++)
    { 
    if(s1[i]!='\0')
         l++;
    else
        break; 
    }
return l;
}
// reverse the string
void reverse(char s1[100],int l)
{
    for(int i=l-1;i>=0;i--)
    cout<<s1[i];
    cout<<endl;
}
//concatenate the string
void con(char s1[100],char s2[100],int l1, int l2)
{
    char s[200];
    for(int i=0;i<l1;i++)
    s[i]=s1[i];
    for(int i=0;i<=l2;i++)
    s[i+l1]=s2[i];
    cout<<"The concatenate string is:  "<< s<<endl;  
}



int main()
{
    char s1[100],s2[100],s3[200];
    int l1,l2;
    cout<<"Entre the  string"<<endl;
    cin>>s1;

    l1=len(s1);
    cout<<"Length of string is "<<l1<<endl;

    cout<<"Reverse string is: "<<endl;
    reverse(s1,l1);
    
    cout<<"Enter the string to concatenate"<<endl;
    cin>>s2;
    l2=len(s2);
    con(s1,s2,l1,l2);
   
    return 0;
}