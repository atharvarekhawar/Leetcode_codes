class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal)-solve(nums,goal-1);
    }
    int solve(vector<int>& nums, int goal){
        if(goal<0){
            return 0;
        }

        int count=0;
        int i=0;
        int j=0;
        int sum=0;

        while(i<nums.size()){
            sum+=nums[i];
            while(j<nums.size() && sum>goal){
                sum-=nums[j];
                ++j;
            }
            count+= i-j+1;
            ++i;
        }

        return count;
    }
};