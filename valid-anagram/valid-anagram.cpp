class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(n!=m)return false;

        unordered_map<int,int>sCount;
        unordered_map<int,int>tCount;

        for(int i=0;i<n;i++){
            sCount[s[i]-'a']++;
            tCount[t[i]-'a']++;
        }

        for(const auto& pair:sCount){
            if(pair.second != tCount[pair.first]){
                return false;
            }
        }
        return true;


    }
};