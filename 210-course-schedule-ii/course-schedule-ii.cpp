class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>dependents(numCourses);
        vector<int>inDegree(numCourses);
        queue<int>q;
        vector<int>res;

        for(auto pre:prerequisites){
            dependents[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        for(int i=0;i<numCourses;++i){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int course = q.front();
            q.pop();

            res.push_back(course);

            for(auto dep:dependents[course]){
                inDegree[dep]--;
                if(inDegree[dep]==0){
                    q.push(dep);
                }
            }

        }

        if(res.size()==numCourses){
            return res;
        }

        return {};
    }
};