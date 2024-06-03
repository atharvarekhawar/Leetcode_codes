class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& visited) {
        for (int i = 0; i < graph[node].size(); ++i) {
            if (visited[graph[node][i]] == -1) {
                visited[graph[node][i]] = visited[node] == 0 ? 1 : 0;
                if(!dfs(graph,graph[node][i],visited)){
                    return false;
                }
            } else {
                if (visited[node] == visited[graph[node][i]]) {
                    return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int m = graph.size();

        vector<int> visited(m, -1);

        for(int i=0;i<m;++i){
            if(visited[i]==-1){
                visited[i]=0;
                if(!dfs(graph,i,visited)){
                    return false;
                }
            }
        }

        
        return true;
    }
};