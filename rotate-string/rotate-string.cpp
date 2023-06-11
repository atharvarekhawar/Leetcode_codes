class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        int m=goal.length();
        if(n!=m){
            return false;
        }
        if(s==goal){
            return true;
        }

        for(int i=1;i<n;i++){
           char temp = s[0];
           s = s.substr(1,n)+temp;
           if(s==goal){
               return true;
           }
        }
        return false;
       

    }
};