#include<iostream>
#include<vector>
using namespace std;
bool binary_search(vector<vector<int>> &mat,int row,int col,int target)
{
    int s=0;
    int e=row*col-1;
    int m=(s+e)/2;
    while(s<=e)
    {   m=(s+e)/2;
        int element=mat[m/col][m%col];
        if(element==target)
        return true;
        if(element>target)
            e=m-1;
        else
            s=m+1;

    }
    return false;

}

int main()
{    int row=3,col=4;
    vector<vector<int>> mat={{1,2,3,4},{6,9,10,11},{14,17,20,21}};
    int target=0;
    cout<<"entre the target element "<<endl;
    cin>>target;
    if(binary_search(mat,row,col,target))
        cout<<"Target is present"<<endl;
    else
        cout<<"Target is not present"<<endl;
    return 0;
}