class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
    int solve(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> store;
        int l = 0;
        int r = 0;
        int count = 0;

        while (r < n) {
            store[nums[r]]++;

            while (l <= r && store.size() > k) {
                store[nums[l]]--;
                if (store[nums[l]] == 0) {
                    store.erase(nums[l]);
                }
                ++l;
            }

            count+=r-l+1;
            ++r;
        }

        return count;
    }
};