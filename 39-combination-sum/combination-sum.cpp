class Solution {
public:
    void solve(vector<vector<int>>&res,vector<int>&candidates,vector<int>&output,int sum,int i){
        if(i>=candidates.size()){
            if(sum==0){
                res.push_back(output);
            }
            return;
        }

        if(candidates[i]<=sum){
            int val = candidates[i];
            output.push_back(val);
            solve(res,candidates,output,sum-val,i);
            output.pop_back();
        }

        solve(res,candidates,output,sum,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>output;
        solve(res,candidates,output,target,0);
        return res;
    }
};