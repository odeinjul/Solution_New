class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, p;
        if(target <= nums.at(l))
            return l;
        else if(target > nums.at(r))
            return r+1;
        while(l<=r){
            p = (l + r) >> 1;
            if(p == 0){
                return 1;
            }
            if(nums.at(p-1) < target && nums.at(p) >= target)
                return p;
            //else if(nums.at(p-1)<target && nums.at(p)>=target)
                //return p
            else if(nums.at(p-1) >= target){
                r = p - 1;
            }
            else{
                l = p + 1;
            }
        }
        return p;
    }
};