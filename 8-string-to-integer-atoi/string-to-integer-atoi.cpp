class Solution {
public:
    long atoi(string s,int i,int sign,long res){
        if(sign*res>=INT_MAX){
            return INT_MAX;
        }
        if(sign*res<=INT_MIN){
            return INT_MIN;
        }
        if(i>=s.size() || s[i]<'0' || s[i]>'9'){
            return sign*res;
        }

        res = atoi(s,i+1,sign,(res*10+(s[i]-'0')));

        return res;
    }
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        int sign = 1;

        while(i<n && s[i]==' '){
            ++i;
        }

        if(s[i]=='-'){
            sign = -1;
            ++i;
        }
        else if(s[i]=='+'){
            ++i;
        }

        return atoi(s,i,sign,0);
    }
};