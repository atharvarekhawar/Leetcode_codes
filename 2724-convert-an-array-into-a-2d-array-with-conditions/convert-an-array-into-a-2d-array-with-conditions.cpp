class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>store;

        int maxCount=0;

        for(auto i:nums){
            store[i]++;
            maxCount = max(maxCount,store[i]);
        }

        vector<vector<int>>res(maxCount);


        for(auto it:store){
            int i=0;
            
            while(i<maxCount && it.second>0){
                res[i].push_back(it.first);
                i++;
                it.second--;
            }
        }

        return res;
    }
};