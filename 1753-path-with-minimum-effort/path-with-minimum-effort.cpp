class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1}; 

        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;

        pq.push({dist[0][0],{0,0}});

        while(!pq.empty()){
            auto cell  = pq.top();
            pq.pop();

            int row = cell.second.first;
            int col = cell.second.second;
            int diff = cell.first;

            for(int i=0;i<4;++i){
                int newr = row + dr[i];
                int newc = col + dc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m){
                    int newEffort = max(abs(heights[row][col] - heights[newr][newc]),diff);
                    if(newEffort<dist[newr][newc]){
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort,{newr,newc}});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};