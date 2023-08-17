class Solution {
private:
    int findMax(vector<int>& piles){
        int maxi = INT_MIN;

        for(int i=0;i<piles.size();i++){
            maxi= max(piles[i],maxi);
        }

        return maxi;
    }

    long long findTotalHours(vector<int>& piles, int perHour){
        long long total=0;

        for(int i=0;i<piles.size();i++){
            total+= ceil((double)piles[i]/(double)perHour);
        }
        return total;
    }

    int solve(vector<int>& piles, int h){
        int low=1;
        int high = findMax(piles);

        while(low<=high){
            int mid = low + (high-low)/2;
            long long requiredHours = findTotalHours(piles,mid);
            if(requiredHours<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return low;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = solve(piles,h);
        return ans;
    }
};