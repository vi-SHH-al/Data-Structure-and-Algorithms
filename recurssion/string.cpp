#include<iostream>
using namespace std;
bool palindrome(string s,int i,int j)
{
    if(i>j)
    return true;
    if(s[i]!=s[j])
        return false;
    else
    {   i++;
        j--;
        return palindrome(s,i,j);
    }
}
void reverse(string& s,int i,int j)
{   
    if(i>j)
    return ;
    
    swap(s[i],s[j]);
    i++;
    j--;

    reverse(s,i,j);
}
int main()
{
    string s="recurssion";
    reverse(s,0,s.length()-1);
    cout<<"reverse of recurssion is : "<<s<<endl<<endl;

    string s1="racecar";
    if(palindrome(s1,0,s1.length()-1))
    cout<<s1<<" is palindrome string"<<endl<<endl;
    else
    cout<<s1<<" is not palindrome string"<<endl<<endl;
    return 0;
}