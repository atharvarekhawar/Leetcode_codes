class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size() - 1;
        }

        int n = nums.size();
        int jumps = 1;
        int currEnd = nums[0];
        int farthest = nums[0];

        for (int i = 1; i < n-1; ++i) {
            farthest = max(farthest, i + nums[i]);

            if (i == currEnd) {
                ++jumps;
                currEnd = farthest;
            }
        }

        return jumps;
    }
};