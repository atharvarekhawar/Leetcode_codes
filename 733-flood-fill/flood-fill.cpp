class Solution {
public:
    struct value{
        int row;
        int col;
    };
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        vector<vector<bool>>visited(m,vector<bool>(n,false));

        int startPixelColor = image[sr][sc];

        visited[sr][sc] = true;

        queue<value>q;
        q.push({sr,sc});

        while(!q.empty()){
            auto pixel = q.front();
            q.pop();

            int row = pixel.row;
            int col = pixel.col;

            visited[row][col] = true;

            image[row][col] = color;

            if(row-1>=0 && !visited[row-1][col] && image[row-1][col]==startPixelColor){
                q.push({row-1,col});
            }
            if(row+1<m && !visited[row+1][col] && image[row+1][col]==startPixelColor){
                q.push({row+1,col});
            }
            if(col-1>=0 && !visited[row][col-1] &&  image[row][col-1]==startPixelColor){
                q.push({row,col-1});
            }
            if(col+1<n && !visited[row][col+1] && image[row][col+1]==startPixelColor){
                q.push({row,col+1});
            }
        }

        return image;
    }
};