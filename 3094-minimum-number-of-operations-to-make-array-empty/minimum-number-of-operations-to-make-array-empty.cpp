class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>store;

        for(auto i:nums){
            store[i]++;
        }

        int count = 0;

        for(auto item:store){
            int curr = item.second;
            if(curr==1) return -1;
            count+=(curr/3);
            if(curr%3) count+=1;
        }

        
        return count;
    }
};