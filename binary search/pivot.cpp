#include<iostream>
using namespace std;
int pivot(int arr[],int size)
{
int s=0;
int e=size-1;
int m=(s+e)/2;
while(s<e)
{
    if(arr[m]>=arr[s])
    s=m+1;
    else
    e=m;
    m=(s+e)/2;
}
return s;
}

int main()
{
    int arr_sorted[]={1,2,3,7,9};
    //after roation
    int arr[]={5,6,7,8,9,10,1,2,3,4};
    cout<<"indes is"<<pivot(arr,10)<<endl;

    return 0;

}