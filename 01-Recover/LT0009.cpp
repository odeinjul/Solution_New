class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 ||( x % 10 == 0 && x!= 0))
            return 0;
        int Revertedx = 0;
        while(x > Revertedx){
            Revertedx = Revertedx * 10 + x % 10;
            x /= 10;
        }
        return x == Revertedx || x == Revertedx /10;
    }
};
//从后面生成回文数，到等长时比较