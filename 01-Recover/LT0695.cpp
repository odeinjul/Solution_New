class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max0 = 0, flag[60][60]={0};
        for(int i = 0; i< grid.size(); i++){
            for(int j = 0; j <grid[i].size(); j++){
                if(flag[i][j]!=2 && grid[i][j]==1){
                    flag[i][j]=2;
                    max0 = max(max0,visit(flag,grid, i, j));
                }   
            }
        }
        return max0;
    }
    int visit(int flag[60][60],vector<vector<int>>& grid, int x, int y){
        int cnt = 1;
        if(x-1 >= 0 && grid[x-1][y] == 1 && flag[x-1][y]!=2){
            flag[x-1][y]=2;
            cnt += visit(flag,grid,x-1,y);
        }
        
        if(y-1 >= 0 && grid[x][y-1] == 1 && flag[x][y-1]!=2){
            flag[x][y-1]=2;
            cnt += visit(flag,grid,x,y-1);
        }
        
        if(x+1 < grid.size() && grid[x+1][y] == 1 && flag[x+1][y]!=2){
            flag[x+1][y]=2;
            cnt += visit(flag,grid,x+1,y);
        }
        
        if(y+1 < grid[x].size() && grid[x][y+1] == 1 && flag[x][y+1]!=2){
            flag[x][y+1]=2;
            cnt += visit(flag,grid,x,y+1);
        }
        return cnt;
    }
};