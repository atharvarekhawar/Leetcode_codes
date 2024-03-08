class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        map<int,int>store;
        int maxCount=1;
        int currCount=0;
        int l=0;
        int r=0;

        while(r<n){
            store[fruits[r]]+=1;
            ++currCount;

            while(store.size()>2){
                store[fruits[l]]-=1;
                --currCount;
                if(store[fruits[l]]==0){
                    store.erase(fruits[l]);
                }
                ++l;
            }

            maxCount = max(maxCount,currCount);
            ++r;
        }
        
        return maxCount;
    }
};