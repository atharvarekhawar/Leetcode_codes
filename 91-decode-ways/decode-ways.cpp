class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0]=='0'){
            return 0;
        }
        int n = s.length();
        vector<int>memo(n+1,0);

        memo[0] = 1;
        memo[1] = 1;
        
        for(int i=2;i<=n;++i){
            int oneDigit = s[i-1] - '0';
            int twoDigit = stoi(s.substr(i-2,2));

            if(oneDigit!=0){
                memo[i] +=memo[i-1];
            }

            if(twoDigit>=10 && twoDigit<=26){
                memo[i] += memo[i-2];
            }
        }

        return memo[n];   
    }
};