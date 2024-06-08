class Solution {
public:
    struct val {
        int index;
        int skill;
        int win;
    };
    int findWinningPlayer(vector<int>& skills, int k) {
        queue<val>q;
        int maxSkill = INT_MIN;
        int maxIndex;

        for(int i=0;i<skills.size();++i){
            q.push({i,skills[i],0});
            if(skills[i]>maxSkill){
                maxSkill = skills[i];
                maxIndex = i;
            }
        }

        val current = q.front();
        q.pop();

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            if(current.index==maxIndex || temp.index==maxIndex){
                return maxIndex;
            }

            if(current.skill > temp.skill){
                current.win++;
                if(current.win==k) return current.index;
                temp.win=0;
                q.push(temp);
            }else{
                temp.win++;
                if(temp.win==k) return temp.index;
                current.win=0;
                q.push(current);
                current = temp;
            }
        }

        return 0;
    }
};