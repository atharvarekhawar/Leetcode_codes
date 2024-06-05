class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>inDegree(numCourses,0);
        vector<vector<int>>store(numCourses);
        queue<int>q;
        int count = 0;

        for(auto pre:prerequisites){
            inDegree[pre[0]]++;
            store[pre[1]].push_back(pre[0]);
        }

        for(int i=0;i<numCourses;++i){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int course = q.front();
            q.pop();
            count++;

            for(auto it:store[course]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }

        return count==numCourses;

    }
};