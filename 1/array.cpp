#include<iostream>
using namespace std;

void reverse(int arr[],int size) 
{   int first=0;
int last= size-1;
    while(first>=last)
    {       int m=arr[first];
        arr[first]=arr[last];
        arr[last]=m;
    }
    print(arr,size);

}
void print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
}
int main()
{
  int arr[]={4,2,6,8,9,20};
int size=sizeof(arr)/sizeof(int);
cout<<reverse(arr,size);

return 0;
} 
