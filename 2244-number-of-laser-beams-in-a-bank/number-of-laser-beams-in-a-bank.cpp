class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m=bank.size();
        int n=bank[0].length();
        if(m==1){
            return 0;
        }

        vector<int>deviceCount(m);

        for(int i=0;i<m;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(bank[i][j]=='1'){
                    count++;
                }
            }
            deviceCount[i]=count;
        }

        int ans=0;
        int currCount=deviceCount[0];

        for(int i=1;i<m;i++){
            if(deviceCount[i]!=0 && currCount==0){
                currCount=deviceCount[i];
                continue;
            }

            if(deviceCount[i]!=0 && currCount!=0){
                ans += (currCount * deviceCount[i]);
                currCount=deviceCount[i];
            }

        }

        return ans;
    }
};