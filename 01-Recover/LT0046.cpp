class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(i!=0){
                swap(nums[0],nums[i]);
                dfs(nums,1);
                swap(nums[0],nums[i]);
                continue;
            }
            else{
                dfs(nums,1);
            }
        }
        return ans;
    }
    void dfs(vector<int> nums,int s){
        if(s==nums.size()){
            ans.push_back(nums);
            return ;
        }
            
        for(int i=s;i<nums.size();i++){
            if(i!=s){
                swap(nums[s],nums[i]);
                dfs(nums,s+1);
                swap(nums[s],nums[i]);
                continue;
            }
            else{
                dfs(nums,s+1);
            }
            
        }
    }
};