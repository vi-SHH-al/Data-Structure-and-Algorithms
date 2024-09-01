//pritnting waveform of a matrix
#include<iostream>
using namespace std;

int main()
{ int row=3,col=3;
    int arr[3][3]={1,2,3,4,5,6,7,8,9};

    for(int j=0;j<col;j++)
    {
        if(j%2==0)
        {
            for(int i=0;i<row;i++)
            cout<<arr[i][j]<<" ";
        }
        else
        {   for(int i=row-1;i>=0;i--)
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}