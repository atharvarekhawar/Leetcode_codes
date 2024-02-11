class Solution {
public:
    void solve(vector<vector<int>>&res,vector<int>output,vector<int>&nums,int idx){
        
        res.push_back(output);

        for(int i=idx;i<nums.size();i++){
            if(i!=idx && nums[i]==nums[i-1]) continue;
            output.push_back(nums[i]);
            solve(res,output,nums,i+1);
            output.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int>output;
        solve(res,output,nums,0);
        return res;
    }
};