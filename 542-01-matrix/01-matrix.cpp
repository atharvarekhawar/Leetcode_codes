class Solution {
public:
    struct cell {
        int row;
        int col;
        int dis;
    };
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>>res(m,vector<int>(n,-1));
        vector<vector<bool>>visited(m,vector<bool>(n,false));

        queue<cell>q;

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                    visited[i][j]=true;
                }
            }
        }

        while(!q.empty()){
            auto cell = q.front();
            q.pop();

            int row = cell.row;
            int col = cell.col;
            int dis = cell.dis;

            res[row][col] = dis;

            if(row-1>=0 && mat[row-1][col]==1 && visited[row-1][col]==false){
                q.push({row-1,col,dis+1});
                visited[row-1][col] = true;
            }
            if(row+1<m && mat[row+1][col]==1 && visited[row+1][col]==false){
                q.push({row+1,col,dis+1});
                visited[row+1][col] = true;
            }
            if(col-1>=0 && mat[row][col-1]==1 && visited[row][col-1]==false){
                q.push({row,col-1,dis+1});
                visited[row][col-1] = true;
            }
            if(col+1<n && mat[row][col+1]==1 && visited[row][col+1]==false){
                q.push({row,col+1,dis+1});
                visited[row][col+1] = true;
            }
        }

        return res;
    }
};