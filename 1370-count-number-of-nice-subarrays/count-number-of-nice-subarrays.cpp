class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
    int solve(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int oddCount = 0;
        int subarrayCount = 0;

        while (j < n) {
            if (nums[j] % 2 != 0) {
                ++oddCount;
            }

            while (i < n && oddCount > k) {
                if (nums[i] % 2 != 0) {
                    --oddCount;
                }
                ++i;
            }

            subarrayCount += j - i + 1;

            ++j;
        }

        return subarrayCount;
    }
};