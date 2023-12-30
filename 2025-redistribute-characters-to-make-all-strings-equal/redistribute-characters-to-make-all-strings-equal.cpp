class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        if(n==1){
            return true;
        }

        unordered_map<char,int>store;

        for(int i=0;i<n;i++){
            for(auto j:words[i]){
                store[j]++;
            }
        }

        bool flag = true;

        for(auto it:store){
            if(it.second % n != 0 ){
                return false;
            }
        }

        return flag;
    }
};