class Solution {
public:
    void solve(vector<vector<int>>&res, vector<int>&candidates,vector<int>output, int target,int i) {
        if (i >= candidates.size()) {
            if(target==0){
                res.push_back(output);
            }
            return;
        }

        if(candidates[i]<=target){
            output.push_back(candidates[i]);
            solve(res,candidates,output,target-candidates[i],i);
            output.pop_back();
        }

        solve(res,candidates,output,target,i+1);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>output;
        solve(res, candidates,output, target, 0);
        return res;
    }
};