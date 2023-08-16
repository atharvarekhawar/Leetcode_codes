class Solution {
private:
    int fibb(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int ans=fibb(n-1)+fibb(n-2);
        return ans;
    }
    
public:
    int fib(int n) {
        return fibb(n);
    }
};