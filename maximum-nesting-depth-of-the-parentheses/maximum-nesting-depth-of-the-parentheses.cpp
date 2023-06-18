class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int res=0;
        int n=s.length();
        if(n==0){
            return 0;
        }

        stack<char>st;
        
        for(auto i:s){
            if(i=='('){
                st.push(i);
                ans++;
            }
            else if(i==')'){
                res=max(res,ans);
                st.pop();
                ans--;  
            }
        }

        return res;
    }
};