class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n==1){
            return s;
        }

        string res="";
        int len=0;
        int start=0;
        int end=0;

        for(int i=1;i<n;i++){
          int j=i-1;
          int k=i+1;

          //for odd
          while(j>=0 && k<n && s[j]==s[k]){
             if(k-j+1 > len){
                 len=k-j+1;
                 start=j;
                 end=k;
             }
             j--;
             k++;
          }

          j=i-1;
          k=i;
          
          //for even
          while(j>=0 && k<n && s[j]==s[k]){
             if(k-j+1 > len){
                 len=k-j+1;
                 start=j;
                 end=k;
             }
             j--;
             k++;
          }
        }

        for(int i=start;i<=end;i++){
            res+=s[i];
        }
          
          return res;
    }
};