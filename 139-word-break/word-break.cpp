class Solution {
public:
    int dp[301];
    bool solve(vector<string>& wordDict,string &s,int idx){
        if(idx==s.length()){
            return true;
        }

        if(dp[idx]!=-1){
            return dp[idx];
        }

        if(find(wordDict.begin(),wordDict.end(),s)!=wordDict.end()){
           return dp[idx]=true;
        }

        for(int i=1;i<=s.length();++i){
            string temp = s.substr(idx,i);

            if(find(wordDict.begin(),wordDict.end(),temp)!=wordDict.end() && solve(wordDict,s,idx+i)){
                return dp[idx]=true;
            }
        }

        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof dp);
        return solve(wordDict,s,0);
    }
};