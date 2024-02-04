class Solution {
#define mod 1000000007
public:
    long long power(long long x, long long y) {
        if (y == 0) {
            return 1;
        }

        if(y==1){
            return x;
        }

        long long ans = power(x, y / 2);
        if (y % 2 == 0) {
            ans *= ans;
            ans%=mod;
        }
        else{
            ans*=ans*x;
            ans%=mod;
        }

        return ans;
    }
    int countGoodNumbers(long long n) {
        long long odd = n / 2;
        long long even = n / 2 + n % 2;

        return (power(5, even) * power(4, odd)) % mod;
    }
};