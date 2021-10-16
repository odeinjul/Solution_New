class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
        int m = mat.size(), n = mat[0].size();
        if(m == 0) return mat;
        vector<vector <int>> dist(m, vector<int> (n , INT_MAX)); //init mat with INT_MAX
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
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
                    if(dist[x0][y0] > dist[temp.first][temp.second] + 1){
                        dist[x0][y0] = dist[temp.first][temp.second] + 1;
                        q.push({x0,y0});
                    }
                }
            }
        }
        return dist;
    }
};