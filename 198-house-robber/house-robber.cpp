class Solution {
private:
    int solve(vector<int>& nums,int i,vector<int>& dp){
        if(i>nums.size()-1)
            return 0; 
        if(i==nums.size()-1)
           return nums[nums.size()-1];

        if(dp[i]!=-1){
            return dp[i];
        }

        int included = solve(nums,i+2,dp) + nums[i];
        int excluded = solve(nums,i+1,dp);

        dp[i] = max(included,excluded);

        return dp[i];


    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        int ans = solve(nums,0,dp);
        return ans;
    }
};