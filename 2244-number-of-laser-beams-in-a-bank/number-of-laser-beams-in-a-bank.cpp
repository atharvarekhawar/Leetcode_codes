class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();
        int n = bank[0].length();

        if(m==1){
            return 0;
        }

        int ans=0;
        int prevCount = 0;


        for(int i=0;i<m;i++){
            int currCount = count(bank[i].begin(),bank[i].end(),'1');

            if(currCount==0){
                continue;
            }

            ans += currCount * prevCount;
            prevCount = currCount;
        }

        return ans;
    }
};