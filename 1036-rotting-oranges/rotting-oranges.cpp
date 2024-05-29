class Solution {
public:
    struct value{
        int row;
        int col;
        int time;
    };
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));

        queue<value>q;
        int maxTime = 0;

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                    visited[i][j] = 2;
                }
            }
        }

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            int row = temp.row;
            int col = temp.col;
            int time = temp.time;

            maxTime = max(maxTime,time);


            if(row-1>=0 && visited[row-1][col]!=2 && grid[row-1][col]==1){
                visited[row-1][col] = 2;
                q.push({row-1,col,time+1});
            }

            if(row+1<m && visited[row+1][col]!=2 && grid[row+1][col]==1){
                visited[row+1][col] = 2;
                q.push({row+1,col,time+1});
            }

            if(col-1>=0 && visited[row][col-1]!=2 && grid[row][col-1]==1){
                visited[row][col-1] = 2;
                q.push({row,col-1,time+1});
            }

            if(col+1<n && visited[row][col+1]!=2 && grid[row][col+1]==1){
                visited[row][col+1] = 2;
                q.push({row,col+1,time+1});
            }
        }

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(visited[i][j]==0 && grid[i][j]==1){
                    return -1;
                }
            }
        }

        return maxTime;
    }
};