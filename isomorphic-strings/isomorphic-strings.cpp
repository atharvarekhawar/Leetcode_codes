class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()){
            return 0;
        }
        unordered_map<char,char>m;

        int n=s.length();
        for(int i=0;i<n;i++){
            int chS = s[i];
            int chT = t[i];
           if(m.count(chS)>0){
               if(m[chS]!=chT){
                   return false;
               }
           }
           else{
              for(const auto& pair:m){
                  if(pair.second == chT){
                      return false;
                  }
              }
           }

           m[chS]=chT;
        }

        return true;
    }
};