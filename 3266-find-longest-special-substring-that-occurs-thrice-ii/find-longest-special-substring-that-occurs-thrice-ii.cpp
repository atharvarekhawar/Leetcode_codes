class Solution {
public:
    int maximumLength(string s) {
        vector<multiset<int>>store(26);
        int n = s.length();

        int count = 1;
        int ans = -1;

        store[s[0]-'a'].insert(1);

        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                count++;
            }else{
                count=1;
            }

            store[s[i]-'a'].insert(count);

            if(store[s[i]-'a'].size() > 3){
                store[s[i]-'a'].erase(store[s[i]-'a'].begin());
            }
        }

        for(int i=0;i<26;i++){
            if(store[i].size()==3){
                ans = max(ans,*store[i].begin());
            }
        }

        return ans;
    }
};