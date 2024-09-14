// 130. Surrounded Regions
// Replace O's with X's



class Solution {
public:
 void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &mat){
        visited[row][col] = 1;
        int n=mat.size();
        int m = mat[0].size();
        int delrow []={1,0,-1,0};
        int delcol[] = {0,1,0,-1};
        
        for(int i=0; i<4;i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            
            if( nrow>=0 && nrow<n && ncol<m && ncol>=0 && !visited[nrow][ncol] && mat[nrow][ncol] == 'O'){
                dfs(nrow, ncol, visited, mat);
            }
        }
        
    }
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        
        for(int j = 0 ;j<m; j++){
            if( !visited[0][j] && mat[0][j] == 'O')
                dfs(0,j, visited, mat);
            
            if( !visited[n-1][j] && mat[n-1][j] == 'O')
                dfs(n-1,j, visited, mat);
        }
        
        for(int i=0; i<n;i++){
            if( !visited[i][0] && mat[i][0] == 'O')
                dfs(i, 0, visited, mat);
            
            if( !visited[i][m-1] && mat[i][m-1] == 'O')
                dfs(i, m-1, visited, mat);
        }
        
        for(int i=0; i<n;i++)
            for(int j=0; j<m;j++)
                if(!visited[i][j] && mat[i][j] == 'O')
                    mat[i][j] = 'X';
        
        
        
    }
};