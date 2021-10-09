class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int flag = 0;
        for(int i = 0; i < nums.size(); i++){
            nums[i]*= nums[i];
            if(abs(nums[flag]) >= nums[i] ){
                flag = i;
            }
        }
        int i = flag-1 , j = flag+1;
        vector<int> temp;
        temp.push_back(nums[flag]);
        while(i>=0 && j< nums.size()){
            if(nums[i] >= nums[j]){
                temp.push_back(nums[j]);
                j++;
            }
            else{
                temp.push_back(nums[i]);
                i--;
            }
        }
        if(j<nums.size()){
            for(;j<nums.size();j++){
                temp.push_back(nums[j]);
            }
            
        }
        else{
            for(;i>=0;i--){
                temp.push_back(nums[i]);
            }
        }
        nums=temp;
        return nums;
    }
};