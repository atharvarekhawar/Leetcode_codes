class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int l=0;
        int r=0;
        vector<int>store(3,0);
        int count=0;

        while(r<n){
            store[s[r]-'a']+=1;
            while(store[0]>=1 && store[1]>=1 && store[2]>=1){
                count+=(n-r);
                store[s[l++]-'a']-=1;
            }
            ++r;
        }

        return count;
    }
};