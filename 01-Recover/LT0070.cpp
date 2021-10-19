class Solution {
public:
    int ans[50];
    int climbStairs(int n) {
        if(n==0)return 1;
        if(n==1)return 1;
        if(ans[n-2]!=0){
            if(ans[n-1]!=0){
                ans[n] = ans[n-1]+ans[n-2];
                return ans[n];
            }
            else{
                ans[n]=climbStairs(n-1)+ans[n-2];
                return ans[n];
            }
        }
        ans[n]=climbStairs(n-2)+climbStairs(n-1);
        return ans[n];
    }
};