class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        if(n<=0||k<=0||k>n) return ans;
        vector<int> path;
        dfs(1,k,n,path);
        return ans;
    }
    void dfs(int start, int k, int n, vector<int> path){
        if(path.size()==k){
            ans.push_back(path);
            return;
        }
            
        else{
            for(int i=start; i <= n - (k-path.size())+1; i++ ){
                path.push_back(i);
                dfs(i+1, k, n, path);
                path.pop_back();
            }
                
        }
    }
};