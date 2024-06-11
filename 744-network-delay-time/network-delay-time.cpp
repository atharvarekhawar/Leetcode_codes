class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,1e9);

        vector<vector<pair<int,int>>>adj(n+1);

        for(auto it:times){
            int from = it[0];
            int to = it[1];
            int weight = it[2];

            adj[from].push_back({to,weight});
        }

        dist[0]=INT_MIN;
        dist[k]=0;

        queue<pair<int,int>>q;

        q.push({k,0});

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            int node = temp.first;
            int weight = temp.second;

            for(auto it:adj[node]){
                int nextNode = it.first;
                int requiredWeight = it.second;

                if(weight + requiredWeight < dist[nextNode]){
                    dist[nextNode] = weight + requiredWeight;
                    q.push({nextNode,weight + requiredWeight});
                }
            }
        }

        int maxTime = INT_MIN;

        for(auto dis:dist){
            if(dis==1e9) return -1;

            maxTime = max(maxTime,dis);
        }

        return maxTime;
    }
};