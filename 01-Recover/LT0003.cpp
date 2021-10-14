class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")
            return 0;
        int lens[50010], max0 = 1,flag = 0;
        memset(lens,0,sizeof(int));
        lens[0]=1;
        for(int i = 1; i < s.length(); i++){
            flag = 0;
            for(int j = i-1; j >= i-lens[i-1]; j--){
                if(s[i] == s[j]){
                    lens[i] = i-j;
                    flag = 1;
                    //return lens[i];
                    break;
                }
            }
            if(flag == 0){
                lens[i] = lens[i-1] +1;
            }
            if(lens[i]>max0){
                max0 = lens[i];
            }
        }
        return max0;
    }
};