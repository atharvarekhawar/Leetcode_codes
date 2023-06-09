class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>stk;
        string ans="";
        int n=s.length();
        int start=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(stk.size()>0){
                    ans+='(';
                }
                stk.push(s[i]);
            }
            else{
                if(stk.size()>1){
                    stk.pop();
                    ans+=')';
                }
                else{
                    stk.pop();
                }
            }
        }
        return ans;
    }
};