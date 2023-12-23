class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>,bool>coords;

        coords.insert(make_pair(make_pair(0, 0), true));

        int x=0;
        int y=0;

        bool ans = false;

        for(auto i:path){
            if(i=='N'){
                y++;
            }else if(i=='E'){
                x++;
            }else if(i=='S'){
                y--;
            }else{
                x--;
            }

           ans = coords.find({x, y}) != coords.end() ;

           if(ans){
               break;
           }else{
               coords[{x,y}] = true;
           }
        }

        return ans;
    }
};