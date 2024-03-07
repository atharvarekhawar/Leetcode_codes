class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zeroCount = 0;
        int l = 0;
        int r = 0;
        int maxLength = 0;

        while (r<n) {
            if(nums[r]==0) ++zeroCount;

            while(zeroCount>k){
                if(nums[l]==0) --zeroCount;
                ++l;
            }

            maxLength = max(maxLength,r-l+1);
            ++r;
        }

        return maxLength;
    }
};