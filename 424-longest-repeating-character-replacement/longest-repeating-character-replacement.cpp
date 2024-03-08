class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int>store(26,0);
        int maxLength=0;
        int topFreq=0;
        int l=0;
        int r=0;

        while(r<n){
            store[s[r]-'A']+=1;
            topFreq = max(topFreq,store[s[r]-'A']);
            while((r-l+1)-topFreq > k){
                store[s[l]-'A']--;
                ++l;
            }
            maxLength = max(maxLength,r-l+1);
            ++r;
        }

        return maxLength;
    }
};