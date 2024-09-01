#include<iostream>
#include<math.h>
using namespace std;

void fib(int n)
{
    int a=0;
    int b=1;
    
    for(int i=1;i<=n;i++)
    {
        int c=a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }
}
int main()
{
int n;
cin>>n;
fib(n);

}