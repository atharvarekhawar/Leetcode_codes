class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string curr="";
        for(int i=0;i<s.length();i++){
          if(s[i] != ' '){
              curr+=s[i];
          }
          else if(curr!=""){
              st.push(curr);
              curr="";
          }
        }
        if(st.size()!=1 && curr!=""){
            st.push(curr);
        }
       
        string ans="";

        while(!st.empty()){
            string curr = st.top();
            st.pop();
            ans+=curr;
            if(!st.empty()){
                ans+=" ";
            }
        }

        return ans;
    }
};