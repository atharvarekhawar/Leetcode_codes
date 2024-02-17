class Solution {
public:
    void solve(vector<vector<int>>& res, vector<int> store, int k, int n,int sum, int i) {
        if (sum > n)
            return;
        if (k == 0) {
            if (sum == n) {
                res.push_back(store);
            }
            return;
        }

        if (i == 10)
            return;

        store.push_back(i);
        sum += i;
        solve(res, store, k - 1, n, sum, i + 1);
        store.pop_back();
        sum -= i;
        solve(res, store, k, n, sum, i + 1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> store;
        solve(res, store, k, n, 0, 1);
        return res;
    }
};