#include<bits/stdc++.h>

using namespace std;

//next smallest element
int* NSE(int arr[],int n)
{
    stack<int> s;
    s.push(-1);
    int *ans=new int[n];
    for(int i=n-1;i>=0;i--)
    {
        while(s.top() >= arr[i])
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(arr[i]);
    }
    return ans;
}

//previous smallest element
int* PSE(int arr[],int n)
{
    stack<int> s;
    s.push(-1);
    int* ans=new int(n);
    for(int i=0;i<n;i++)
    {
        while(s.top() >= arr[i])
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(arr[i]);
    }
    return ans;
}

//next greatest element
int*   NGE(int arr[],int n)
{
    stack<int> s;
    s.push(-1);
    int *ans=new int[n];
    for(int i=n-1;i>=0;i--)
    {
        while(s.top()!= -1 && s.top() <= arr[i])
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(arr[i]);
    }
    return ans;
}

// previous greatest element
int* PGE(int arr[],int n)
{
    stack<int> s;
    s.push(-1);
    int *ans=new int[n];
    for(int i=0;i<n;i++)
    {
        while(s.top()!= -1 && s.top() <= arr[i])
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(arr[i]);
    }
    return ans;
}
int main()
{
    int arr[]={4,1,9,4,0,1,7,2};
    int *ans=NSE(arr,8);

    cout<<"Next smallest element: \n";
    for(int i=0;i<8;i++)
        cout<<ans[i]<<" ";
    cout<<endl;

    ans=PSE(arr,8);
    cout<<"Previous smallest element: \n";
    for(int i=0;i<8;i++)
        cout<<ans[i]<<" ";
    cout<<endl;

    ans=NGE(arr,8);
    cout<<"Next greatest element: \n";
    for(int i=0;i<8;i++)
        cout<<ans[i]<<" ";
    cout<<endl;

    ans=PGE(arr,8);
    cout<<"Previous greatest element: \n";
    for(int i=0;i<8;i++)
        cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}