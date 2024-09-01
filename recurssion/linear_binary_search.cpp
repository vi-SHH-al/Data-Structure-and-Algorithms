#include <iostream>
using namespace std;

bool bs(int arr[],int s,int e,int k)
{
    int mid=s+e;
    if(s>e)
    return false;

    if(arr[mid]==k)
    return true;

    if(arr[mid]<k)
    return bs(arr,mid+1,e,k);
    
    else
    return bs(arr,s,mid-1,k); 
}

bool ls(int arr[],int size,int k)
{
    if(size==0)
    return false;
    if(arr[0]!=k)
    return ls(arr+1,size-1,k);
    else
    return true;
}

int main()
{
    int arr[]={1,2,3,4,5};
    int size =5;
    int k=4;
    cout<<"by linear search"<<endl;
    if(ls(arr,size,k))
    cout<<"found"<<endl;
    else
    cout<<"not found"<<endl;

    cout<<endl<<"by binary search"<<endl;
    if(bs(arr,0,size,k))
    cout<<"found"<<endl<<endl;
    else
    cout<<"notfounnd"<<endl<<endl;

    return 0;
}