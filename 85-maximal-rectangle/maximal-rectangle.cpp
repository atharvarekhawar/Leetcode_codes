class Solution {
public:
    int largestArea(vector<int>&arr){
        int n=arr.size();
        vector<int>prevSmall(n);
        vector<int>nextSmall(n);
        stack<int>st;

        for(int i=0;i<n;++i){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                prevSmall[i]=st.top()+1;
            }else{
                prevSmall[i]=0;
            }
            st.push(i);
        }

        st=stack<int>();

        for(int i=n-1;i>=0;--i){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nextSmall[i]=st.top()-1;
            }else{
                nextSmall[i]=n-1;
            }
            st.push(i);
        }

        int maxArea = INT_MIN;

        for(int i=0;i<n;++i){
            int currArea = ((nextSmall[i]-prevSmall[i])+1)*arr[i];
            maxArea = max(maxArea,currArea);
        }

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>histogram(matrix[0].size(),0);
        int maxArea = INT_MIN;

        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                if(matrix[i][j]=='1'){
                    histogram[j]++;
                }
                else{
                    histogram[j]=0;
                }
            }
            maxArea = max(maxArea,largestArea(histogram));
        }

        return maxArea;
    }
};