class Solution {
public:
   int findSum(vector<int>& weights,int n){
       int sum = 0;

       for(int i=0;i<n;i++){
           sum+=weights[i];
       }
       return sum;
   }
   int findMin(vector<int>& weights,int n){
       int mini = INT_MAX;

       for(int i=0;i<n;i++){
           mini = min(mini,weights[i]);
       }
       return mini;
   }
   bool checkWeight(vector<int>& weights,int days,int n,int mid){
       int curr=0;
       int cnt=0;
       int cntIndex=0;

       for(int i=0;i<n;i++){
           if(weights[i]>mid){
               return false;
           }
           if(curr+weights[i]==mid){
             cnt++;
             cntIndex=i;
             curr=0;
           }
           else if(curr+weights[i] > mid){
              cnt++;
              curr=0;
              cntIndex=i-1;
              curr+=weights[i];
           }
           else{
               curr+=weights[i];
           }
       }

       if(cntIndex != n-1)
          cnt++;
       
       return cnt <= days;
   }
   int solve(vector<int>& weights,int days,int n){
       int high = findSum(weights,n);
       int low  = findMin(weights,n);

       while(low<=high){
           int mid = low+(high-low)/2;
           bool check = checkWeight(weights,days,n,mid);

           if(check){
               high=mid-1;
           }
           else{
               low=mid+1;
           }
       }

       return low;
   }
   int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int ans = solve(weights,days,n);

        return ans;
    }
};
