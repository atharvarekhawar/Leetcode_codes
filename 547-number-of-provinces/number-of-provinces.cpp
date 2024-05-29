class Solution {
public:
    void solve(int node, vector<vector<int>>& isConnected,map<int, bool>& visited) {
        visited[node] = true;

        for (int j = 0; j < isConnected[node].size(); ++j) {
            if (isConnected[node][j] == 1 && !visited[j]) {
                solve(j, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        int n = isConnected.size();

        map<int, bool> visited;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                solve(i, isConnected, visited);
                provinces++;
            }
        }

        return provinces;
    }
};