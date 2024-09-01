#include<iostream>
using namespace std;
int sqrt(int n)
{
    int s=0;
    int e=n;
    int m=(s+e)/2;
    int ans;
    while(s<=e)
    {   if(m*m==n)
        return m;
        if(m*m<=n)
        {s=m+1;
        ans=m;}
        else
        e=m-1;  
         m=(s+e)/2;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<sqrt(n);
return 0;
}