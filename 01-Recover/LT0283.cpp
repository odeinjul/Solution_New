class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=nums.size()-1; i > 0; i--){
            while(nums[i] != 0 && nums[i-1] == 0){
                int a=nums[i];
                nums[i-1] = a;
                nums[i] = 0;
                if(i < nums.size()-1)
                    i++;
            }
        }
    }
};
/*
    void moveZeroes(vector<int>& nums) {
        int counter = 0;
        for(int i=0; i < nums.size(); i++){
            if(nums[i]==0) counter++;
            else nums[i - counter] = nums[i];
        }
        while(counter > 0){
            nums[nums.size()-counter]=0;
            counter--;
        }
    }
    //wjoker
*/