class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();
        vector<int>sample;

        for(int i=0;i<n;i++){
            sample.push_back(points[i][0]);
        }

        sort(sample.begin(),sample.end());

        int diff=INT_MIN;

        for(int i=0;i<n-1;i++){
            diff = max(diff,(sample[i+1]-sample[i]));
        }

        return diff;
    }
};