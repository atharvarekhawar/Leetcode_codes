class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size() < d) return -1; //edge case

        int n=jobDifficulty.size();
        vector<vector<int>> dp(n+1,vector<int>(d+1,1e9));
        dp[n][0]=0; //base case
        for(int idx=n-1;idx>=0;--idx) {
            for(int D=1;D<=d;++D) {
                int maxi=0,ans=1e9;
                for(int i=idx;i<n;++i) {
                    maxi=max(maxi,jobDifficulty[i]);
                    int res=dp[i+1][D-1];
                    if(res!=1e9) ans=min(ans,maxi+res);
                }
                dp[idx][D]=ans;
            }
        }
        return dp[0][d];
    }
};