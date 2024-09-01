#include<iostream>
using namespace std;
int main()
{  int n,m;
cout<<"Entre the number: "<<endl;
cin>>n;
int sum=0;
while(n!=0)
{   m=n%10;
    sum=sum+m*m*m;
    n=n/10;
}
if(sum==n)
cout<<"Its a armstrong no"<<endl;
else
cout<<"not a armstrong no."<<endl;

return 0;
}       