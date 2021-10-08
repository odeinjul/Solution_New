class Solution {
public:
    int search(vector<int>& nums, int target) {
        //int help(int l, int r,int p){
            int p = 0, l = 0, r = nums.size()-1;
            while(l<=r){
                p = (l + r) >> 1;
                if(nums[p] == target) return p;
                if(target < nums[p]) r = p - 1;
                else l = p + 1;
            }
        return -1;
    }
};