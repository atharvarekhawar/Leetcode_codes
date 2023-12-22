class Solution {
public:
    int maxScore(string s) {
        int oneCount=0;
        int zeroCount=0;

        for(auto i:s){
            if(i=='1'){
                oneCount++;
            }
        }

        int score = 0;

        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='0'){
                zeroCount++;
            }
            else{
                oneCount--;
            }
            score = max(score,(zeroCount + oneCount));
        }

        return score;
    }
};