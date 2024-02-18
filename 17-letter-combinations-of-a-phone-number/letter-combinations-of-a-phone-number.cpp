class Solution {
public:
    void solve(vector<string>&res,string store,string digits,int index,string mapping[]){
        if(index>=digits.length()){
            res.push_back(store);
            return;
        }

        int currNum = digits[index]-'0';
        string currString = mapping[currNum];

        for(int i=0;i<currString.length();i++){
            store.push_back(currString[i]);
            solve(res,store,digits,index+1,mapping);
            store.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        
        if(digits.length()==0){
            return res;
        }
        
        string store = "";
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(res,store,digits,0,mapping);
        return res;
    }
};