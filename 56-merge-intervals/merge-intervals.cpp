class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>res;
        int i=1;

        sort(intervals.begin(),intervals.end());

        vector<int>store={intervals[0][0],intervals[0][1]};
        
        while(i<n){
            if(intervals[i][0] <= store[1]){
                store[1] = max(store[1],intervals[i][1]);
                i++;
            }
            else{
                res.push_back(store);
                store[0]=intervals[i][0];
                store[1]=intervals[i][1];
            }
        }

        res.push_back(store);

        return res;
    }
};