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