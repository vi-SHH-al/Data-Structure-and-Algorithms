#include<iostream>
using namespace std;

int peak(int arr[],int size)
{
    int s=0,e=size-1;
    int m= (s+e)/2;

    while(s<=e)
    {
        if(arr[m]<arr[m+1])
        s=m+1;
        else
        e=m;
        m=(s+e)/2;

        
    }
    return arr[m];
}
int main()
{
    int arr[]={1,3,5,6,4,3,2};
    cout<<peak(arr,7);
    return 0;
}
