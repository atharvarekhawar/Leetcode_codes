class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int capacity = nums[0];

        for(int i=1;i<n;i++){
            if(i>capacity){
                return false;
            }

            capacity = max(capacity,i+nums[i]);
        }

        return true;
    }
};