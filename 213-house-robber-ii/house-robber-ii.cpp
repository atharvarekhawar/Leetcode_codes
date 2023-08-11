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
        vector<int>first;
        vector<int>last;
        for(int i=0;i<n;i++){
            if(i != n-1){
                first.push_back(nums[i]);
            }
             if(i != 0){
                last.push_back(nums[i]);
            }
        }
        if(n==1){
            return nums[0];
        }
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        int ans = max(solve(last,0,dp1),solve(first,0,dp2));//to assure both first and last house are not in same solution send two arrays with either of them excluded and return maximun ans.

        return ans;
    }
};