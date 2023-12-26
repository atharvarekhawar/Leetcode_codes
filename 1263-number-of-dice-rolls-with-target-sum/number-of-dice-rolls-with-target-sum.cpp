class Solution {
    const int mod = (int)pow(10, 9) + 7; 
private:
    long long solve(vector<vector<long long>>& dp, int n, int k, int target) {
        if (n == 0 && target == 0) {
            return 1;
        }

        if (n == 0 || target <= 0) {
            return 0;
        }

        if (dp[n][target] != -1) {
            return dp[n][target];
        }

        long long ways = 0;

        for (int i = 1; i <= k; i++) {
            ways += solve(dp, n - 1, k, target - i);
        }

        dp[n][target] = ways % mod;

        return dp[n][target];
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        if (n == 1 && target <= k) {
            return 1;
        }
        if (n == 1 && target > k) {
            return 0;
        }

        vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, -1));

        return solve(dp, n, k, target);
    }
};