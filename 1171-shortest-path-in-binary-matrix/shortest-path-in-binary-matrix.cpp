class Solution {
public:
    struct val {
        int row;
        int col;
        int len;
    };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1]==1){
            return -1;
        }
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        queue<val> q;
        q.push({0, 0, 1});
        dist[0][0] = 1;

        int dr[] = {-1,0,1,0,-1,-1,1,1};
        int dc[] = {0,1,0,-1,-1,1,-1,1};

        while (!q.empty()) {
            val cell = q.front();
            q.pop();

            int row = cell.row;
            int col = cell.col;
            int len = cell.len;

            for(int i=0;i<8;++i){
                int newr = row + dr[i];
                int newc = col + dc[i];

                if(newr >=0 && newc >=0 && newr<n && newc<n && grid[newr][newc] == 0 && len+1 < dist[newr][newc]){
                    dist[newr][newc] = len+1;
                    q.push({newr,newc,len+1});
                }
            }       
        }

        return dist[n - 1][n - 1] == 1e9 ? -1 : dist[n - 1][n - 1];
    }
};