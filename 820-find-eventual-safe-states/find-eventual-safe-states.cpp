class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int m=graph.size();

        vector<vector<int>> revGraph(m);

        for(int i=0;i<m;++i){
            for(auto it:graph[i]){
                revGraph[it].push_back(i);
            }
        }

        vector<int>inDegree(m);

        for(int i=0;i<m;++i){
            for(auto it:revGraph[i]){
                inDegree[it]++;
            }
        }

        queue<int>q;

        for(int k=0;k<m;++k){
            if(inDegree[k]==0){
                q.push(k);
            }
        }

        vector<int>res;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);

            for(auto adj:revGraph[node]){
                inDegree[adj]--;
                if(inDegree[adj]==0){
                    q.push(adj);
                }
            }
        }

        sort(res.begin(),res.end());
        return res;
    }
};