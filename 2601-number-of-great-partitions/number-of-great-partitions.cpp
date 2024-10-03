class Solution {
const long MOD = 1e9 + 7;
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();

        if(n==1){
            return 0;
        }

        long sum = 0;

        for(auto i:nums){
            sum = (sum+i);
        }

        if(sum<2*k) return 0;

        long dp[1000][1001];

        for(int i=0;i<=n;++i){
            dp[0][i]=1;
        }

        for(int j=1;j<k;++j){
            dp[j][0]=0;
        }

        for(int i=1;i<k;++i){
            for(int j=1;j<=n;++j){
                if(i-nums[j-1]>=0){
                    dp[i][j] = (dp[i][j-1] + (dp[i-nums[j-1]][j-1]))%MOD;
                }
                else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }

        int ans= 1;

        for(int i=1;i<=n;++i){
            ans = (ans*2)%MOD;
        }

        for(int i=0;i<k;++i){
            ans=(ans-((2*dp[i][n])%MOD)+MOD)%MOD;
        }

        return ans;




    }
};