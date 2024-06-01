class Solution {
public:
    void dfs(vector<vector<int>>& grid,int row,int col,int m,int n,vector<vector<bool>>&visited){
        visited[row][col] = true;

        if(row-1>=0 && grid[row-1][col]==1 && !visited[row-1][col]){
            dfs(grid,row-1,col,m,n,visited);
        }
        if(row+1<m && grid[row+1][col]==1 && !visited[row+1][col]){
            dfs(grid,row+1,col,m,n,visited);
        }
        if(col-1>=0 && grid[row][col-1]==1 && !visited[row][col-1]){
            dfs(grid,row,col-1,m,n,visited);
        }
        if(col+1<n && grid[row][col+1]==1 && !visited[row][col+1]){
            dfs(grid,row,col+1,m,n,visited);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>>visited(m,vector<bool>(n,false));

        for(int i=0;i<m;++i){
            if(grid[i][0]==1 && !visited[i][0]){
                dfs(grid,i,0,m,n,visited);
            }
            if(grid[i][n-1]==1 && !visited[i][n-1]){
                dfs(grid,i,n-1,m,n,visited);
            }
        }

        for(int j=0;j<n;++j){
            if(grid[0][j]==1 && !visited[0][j]){
                dfs(grid,0,j,m,n,visited);
            }
            if(grid[m-1][j]==1 && !visited[m-1][j]){
                dfs(grid,m-1,j,m,n,visited);
            }
        }

        int count = 0;

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1 && !visited[i][j]){
                    count++;
                }
            }
        }

        return count;

    }
};