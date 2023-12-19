class Solution {
private:
    int smoothen(vector<vector<int>> &img,int x,int y){
        int m=img.size();
        int n=img[0].size();

        int count=0;
        int sum=0;

        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int nx=i+x;
                int ny=j+y;

                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    sum+=img[nx][ny];
                    count++;
                }
            }
        }

        return floor(sum/count);
    }

public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m=img.size();
        int n=img[0].size();
        vector<vector<int>>res(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               res[i][j] = smoothen(img,i,j);
            }
        }

        return res;
    }
};