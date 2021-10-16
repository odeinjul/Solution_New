class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
        int m = mat.size(), n = mat[0].size();
        if(m == 0) return mat;
        vector<vector <int>> dist(m, vector<int> (n , INT_MAX-3000)); //init dist with INT_MAX
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                }
                else{
                    if(i > 0) 
                        dist[i][j] = min(dist[i][j], dist[i-1][j]+1);
                    if(j > 0)
                        dist[i][j] = min(dist[i][j], dist[i][j-1]+1);
                }
            }
        }
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i < m-1) 
                    dist[i][j] = min(dist[i][j], dist[i+1][j]+1);
                if(j < n-1)
                    dist[i][j] = min(dist[i][j], dist[i][j+1]+1);
            }
        }
        /*
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
        }*/
        return dist;
    }
};