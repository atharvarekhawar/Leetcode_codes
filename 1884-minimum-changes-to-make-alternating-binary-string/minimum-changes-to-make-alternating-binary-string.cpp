class Solution {
public:
    int minOperations(string s) {
        if(s.length()==1){
            return 0;
        }

        char curr = '0';
        int zeroAns = 0;

        for(int i=0;i<s.length();i++){
            if(s[i] != curr){
                zeroAns++;
            }

            if(curr=='0'){
                curr = '1';
            }
            else{
                curr='0';
            }
        }

        curr = '1';
        int oneAns = 0;

        for(int i=0;i<s.length();i++){
            if(s[i]!=curr){
                oneAns++;
            }
            if(curr=='0'){
                curr = '1';
            }
            else{
                curr='0';
            }
        }

        return min(zeroAns,oneAns);
        
    }
};