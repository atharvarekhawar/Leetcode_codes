class Solution {
public:
    int isPossible(vector<int>& bloomDay, int m, int n, int day,int k){
       int totalBoq = 0;
       int cnt = 0;

       for(int i=0;i<n;i++){
           if(bloomDay[i] <= day){
               cnt++;
           }
           else{
               totalBoq += (cnt/k);
               cnt=0;
           }
       }
       totalBoq += (cnt/k);
       return totalBoq>=m;
      
    }
    int solve(vector<int>& bloomDay, int m, int n, int k){
       int maxi = INT_MIN;
       int mini = INT_MAX;

       for(int i=0;i<n;i++){
           maxi = max(maxi,bloomDay[i]);
           mini = min(mini,bloomDay[i]);
       }

       int low = mini;
       int high = maxi;

       while(low<=high){
           int mid = low+(high-low)/2;

           int possible = isPossible(bloomDay,m,n,mid,k);

           if(possible){
               high=mid-1;
           }
           else{
               low=mid+1;
           }
       }

       return low;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m*1ll*k*1ll;
        int n = bloomDay.size();
        if(val > n)return -1;

        int ans = solve(bloomDay,m,n,k);

        return ans;
    }
};