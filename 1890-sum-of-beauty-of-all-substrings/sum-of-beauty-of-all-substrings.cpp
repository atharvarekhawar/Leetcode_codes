class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>freq;
            for(int j=i;j<n;j++){
                freq[s[j]]++;
                int maxFreq = 0;
                int minFreq = INT_MAX;
                for(auto it:freq){
                    maxFreq = max(maxFreq,it.second);
                    minFreq = min(minFreq,it.second);
                }
                sum+=(maxFreq-minFreq);             
            }
        }

        return sum;
    }
};