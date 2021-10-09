class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = nums.size() - k % nums.size();
        vector<int> temp = nums;
        for(int i = 0; i < nums.size(); i++){
            nums[i] = temp[(i+k)%nums.size()];
        }
    }
};
/*
    void rotate(vector<int>& nums, int k) 
    {
        k = nums.size() - k % nums.size();
        trotate(nums, 0, k-1);
        trotate(nums, k, nums.size()-1);
        trotate(nums, 0, nums.size()-1);
    }
    void trotate(vector<int>& nums, int l, int r) 
    {
        while(l<r){
            swap(nums[l], nums[r]);
            l++; r--;
        }
    }
    //luliyucoordinate
*/