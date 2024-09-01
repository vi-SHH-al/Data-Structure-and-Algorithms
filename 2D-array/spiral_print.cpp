//pritnting elements of array in spiral form
#include<iostream>
#include<vector>
using namespace std;

int main()
{   vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    vector<int>ans;//ans will contain the spiral matrix in linear form
    int row=matrix.size();
    int col=matrix[0].size();

    
        int count = 0;
        int total = row*col;
        
        //index initialisation
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row-1;
        int endingCol = col-1;
        
        
        while(count < total) {
            
            //print starting row
            for(int index = startingCol; count < total && index<=endingCol; index++) {
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;
            
            //print ending column
            for(int index = startingRow; count < total && index<=endingRow; index++) {
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;
            
            //print ending row
            for(int index = endingCol; count < total && index>=startingCol; index--) {
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;
            
            //print starting column
            for(int index = endingRow; count < total && index>=startingRow; index--) {
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }   
        cout<<"The matrix is : \n";     
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            cout<<matrix[i][j]<<" ";
            cout<<endl;
        }
        cout<<"The spiral is "<<endl;
        for(int i=0;i<row*col;i++)
        cout<<ans[i]<<" ";
        cout<<endl;
      return 0;
}