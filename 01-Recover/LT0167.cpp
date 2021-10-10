class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        for(int i = 0 ;i <= numbers.size()-2; i++){
            int l = i + 1, r = numbers.size()-1,s = target - numbers[i];
            int p, temp = 0;
            while(l<=r){
                p = (l + r) >> 1;
                if(numbers[p] == s){
                    temp = p;
                    break;
                }
                else if(numbers[p] < s) l = p + 1;
                else r = p -1;
            }
            if(numbers[p] != s)
                continue;
            else{
                ans.push_back(i+1); ans.push_back(temp+1);
                break;
            }
        }
        return ans;
    }
};