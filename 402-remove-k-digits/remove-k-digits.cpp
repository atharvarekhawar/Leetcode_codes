class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        stack<char>st;

        for(int i=0;i<n;++i){
            while(!st.empty() && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            if(!st.empty()){
                st.push(num[i]);
            }else{
                if(num[i]!=0){
                    st.push(num[i]);
                }
            }
        }

        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }

        string res="";

        while(!st.empty()){
            res+=st.top();
            st.pop();
        }

        while(!res.empty() && res.back()=='0'){
            res.pop_back();
        }

        reverse(res.begin(),res.end());

        if(res=="") return "0";

        return res;
    }
};