class Solution {
public:
    void solve(vector<vector<string>>&res,vector<string>store,string &s,int index){
        if(index>=s.length()){
            res.push_back(store);
            return;
        }

       for(int i=index;i<s.length();i++){
           if(isPalindrome(s,index,i)){
               store.push_back(s.substr(index,i-index+1));
               solve(res,store,s,i+1);
               store.pop_back();
           }
       }
    }

    bool isPalindrome(string &s,int i,int j){
        while(i<=j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>store;
        solve(res,store,s,0);
        return res;
    }
};