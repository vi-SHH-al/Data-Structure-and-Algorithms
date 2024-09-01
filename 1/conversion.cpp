#include<bits/stdc++.h>
using namespace std;

int binarytodecimal(int n)
{
int ans;
int x=1;
while(n>0)
{
    int y=n%10;
    ans=y*x;
    x*=2;
    n=n/10;
}
return ans;
}

int octaltodecimal(int n)
{    
    int ans;
    int x=1;
    while(n>0)
    {
    int y=n%10;
    ans=y*x;
    x*=8;
    n=n/10;
    }
    return ans;
}

int decimaltobinary(int n)
{ int m;
int ans=0;
    while(n>0)
    {
        m=n%2;
        ans=ans*10+m;
        if(m==0)
        ans*=10;
        n/=2;
    }
return ans;
}
int main()
{
int n;
cin>>n;
cout<<decimaltobinary(n)<<endl;

}