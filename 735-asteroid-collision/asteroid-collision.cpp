class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int>st;
        vector<int>res;

        for(auto i:asteroids){
            if(i<0){
                while(!st.empty() && st.top()>0 && st.top()<abs(i)){
                    st.pop();
                }
                if(st.empty()){
                    st.push(i);
                }
                else if(st.top()==abs(i)){
                    st.pop();
                }else if(st.top()>abs(i)){
                    continue;
                }
                else{
                    st.push(i);
                }
            }else{
                st.push(i);
            }
        }

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};