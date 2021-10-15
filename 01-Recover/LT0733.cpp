class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int cmp = image[sr][sc];
        int flag[60][60]={0};
        image[sr][sc] = newColor;
        flag[sr][sc] = 2;
        bfs(flag,image,sr,sc,cmp,newColor);
        return image;
    }
    void bfs(int flag[60][60],vector<vector<int>>& image,int x, int y, int c, int p){
        if(x+1<image.size() && image[x+1][y] == c && flag[x+1][y]!=2){
            image[x+1][y] = p;
            flag[x+1][y]=2;
            bfs(flag,image,x+1,y,c,p);
        }
        if(y+1<image[x].size() && image[x][y+1] == c && flag[x][y+1]!=2){
            image[x][y+1] = p;
            flag[x][y+1]=2;
            bfs(flag,image,x,y+1,c,p);
        }
        if(x-1>=0 && image[x-1][y] == c && flag[x-1][y]!=2){
            image[x-1][y] = p;
            flag[x-1][y]=2;
            bfs(flag,image,x-1,y,c,p);
        }
        if(y-1>=0 && image[x][y-1] == c && flag[x][y-1]!=2){
            image[x][y-1] = p;
            flag[x][y-1]=2;
            bfs(flag,image,x,y-1,c,p);
        }
        
    }
};
