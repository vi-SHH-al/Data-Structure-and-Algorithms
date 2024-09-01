//Question book: pageno.1
#include<iostream>
using namespace std;
bool ispossible(int arr[],int n,int m,int mid)
{
    int student=1;
    int pagesum=0;

    for(int i=0;i<n;i++)
    {
        if(pagesum+arr[i]<=mid)
            pagesum+=arr[i];
        else
        {    
            student++;
            if(student>m||mid<arr[i])
                return false;
            pagesum=arr[i];  // because book will allocate to the new student
        }

    }
    return true;
}


int allocate_book(int arr[],int n,int m)
{
    int s=0;
    int sum=0;
    int ans;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    int e=sum;
    int mid=(s+e)/2;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(ispossible(arr,n,m,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else
            s=mid+1;
    }
return ans;
}
int main()
{   int n=4;//total no. of book
    int arr[]={10,20,30,40};//arr size is no of books and its elements is pages of book
    int m=2;//no of students
    cout<<allocate_book(arr,n,m)<<endl;
    return 0;
}