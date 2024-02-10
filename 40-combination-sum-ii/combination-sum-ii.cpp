class Solution {
public:
    void solve(vector<vector<int>>& res, vector<int>& candidates,vector<int>& output, int target, int idx) {
        if (target == 0) {
            res.push_back(output);
            return;
        }

        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;

            output.push_back(candidates[i]);
            solve(res,candidates,output,target-candidates[i],i+1);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> output;
        sort(candidates.begin(), candidates.end());
        solve(res, candidates, output, target, 0);
        return res;
    }
};