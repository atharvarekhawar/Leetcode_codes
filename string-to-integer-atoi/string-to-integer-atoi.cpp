class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        if(n==0){
            return 0;
        }

        double ans = 0;
        int i=0;

        while(s[i] == ' '){
            i++;
        }

        bool negative = s[i]=='-';
        bool positive = s[i]=='+';
        positive == true ? i++: i;
        negative == true ? i++: i;

       while(i<n && s[i]>='0' && s[i]<='9'){
           ans=ans*10 + s[i]-'0';
           i++;
       }
       
         ans = negative?-ans:ans;
         ans = (ans>INT_MAX)? INT_MAX : ans;
         ans = (ans<INT_MIN)? INT_MIN : ans;

         return ans;


    }
};