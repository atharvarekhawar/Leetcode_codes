class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);

        int MOD = (int) (1e9+7);

        for(auto road:roads){
            int first = road[0];
            int second = road[1];
            int time = road[2];

            adj[first].push_back({second,time});
            adj[second].push_back({first,time});
        }

        vector<long long>dist(n,LLONG_MAX);
        vector<long long>ways(n,0);
        dist[0]=0;
        ways[0]=1;

        priority_queue<pair<long long, int>,vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0,0});


        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();

            long long time = temp.first;
            int node = temp.second;
            

            for(auto it:adj[node]){
                int nextNode = it.first;
                long long requiredTime = it.second;

                if(time + requiredTime < dist[nextNode]){
                    dist[nextNode] = time + requiredTime;
                    pq.push({time + requiredTime,nextNode});
                    ways[nextNode] = ways[node];
                }
                else if(time + requiredTime == dist[nextNode]){
                    ways[nextNode] = (ways[nextNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1] % MOD;

    }
};