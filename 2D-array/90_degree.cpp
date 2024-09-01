#include<iostream>
//#include<algorithm>
using namespace std;
int main()
{   
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    int ans[3][3];
    cout<<"matrix before rotation"<<endl;
    for(int i=0;i<3;i++)
    {   
        for(int j=0;j<3;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    for(int i=0;i<3;i++)            // interchanging the rows and column and store it in new arr
        for(int j=0;j<3;j++)
            ans[j][i]=arr[i][j];
    
    for(int i=0;i<3;i++)
        swap(ans[i][0],ans[i][2]);  
            // swapping columns of the ans matrix

    cout<<"\n Matrix after 90 degree rotation"<<endl;
    for(int i=0;i<3;i++)
    {   
        for(int j=0;j<3;j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
        
    return 0;
}