#include<iostream>
using namespace std;
int binarysearch(int arr[],int size,int key)
{
    int s=0;
    int e=size-1;
    int ans=-1;
    while(s<=e)
    {
        int m=(s+e)/2;
        if(arr[m]==key)
        return m;
        else if(arr[m]>key)
        e=m-1;
        else 
        s=m+1;
    }
    return ans;
}
int main()
{
    int arr[7]={1,2,3,4,5,6,7};
    cout<<"The index os 2 is :"<<binarysearch(arr,7,9)<<endl;
    return 0;
}