class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxLength=0;
        int l=0;
        int r=0;
        set<char>store;
        

        for(int i=0;i<n;++i){
            if(store.find(s[i])==store.end()){
                int currLength = r-l+1;
                ++r;
                store.insert(s[i]);
                maxLength = max(maxLength,currLength);
            }else{
                while(!store.empty() && store.count(s[i])!=0){
                    store.erase(s[l++]);
                }
                int currLength = r-l+1;
                maxLength=max(maxLength,currLength);
                ++r;
                store.insert(s[i]);
            }
        }

        //maxLength = max(maxLength,currLength);

        return maxLength;
    }
};  