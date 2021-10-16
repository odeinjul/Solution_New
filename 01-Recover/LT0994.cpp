class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<vector <int>> dist(m, vector<int> (n , INT_MAX-10000)); //init dist with INT_MAX
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int, int> temp = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int x0 = temp.first + dir[i][0];
                int y0 = temp.second + dir[i][1];
                if(x0 >= 0 && y0 >= 0 && x0 < m && y0 <n){
                    if(grid[x0][y0] == 1 && dist[x0][y0] > dist[temp.first][temp.second] + 1){
                        dist[x0][y0] = dist[temp.first][temp.second] + 1;
                        q.push({x0,y0});
                    }
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    ans = max(ans, dist[i][j]);
                }
            }
        }
        if(ans >= INT_MAX-10000)
            return -1;
        return ans;
    }
};