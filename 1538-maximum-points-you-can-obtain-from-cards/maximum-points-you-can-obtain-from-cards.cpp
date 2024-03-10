class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int maxSum=0;
        int currSum=0;
        int l=k;
        int r=n-1;

        for(int i=0;i<k;++i){
            currSum+=cardPoints[i];
        }

        if(k==n){
            return currSum;
        }

        maxSum=max(currSum,maxSum);

        while(l>0){
            currSum-=cardPoints[--l];
            currSum+=cardPoints[r--];
            maxSum=max(currSum,maxSum);
        }

        return maxSum;
    }
};