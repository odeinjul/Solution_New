class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int save[40];
        int cnt =  0;
        while(n>0){
            save[cnt]=n%2;
            n/=2;
            cnt++;
        }
        for(int i=cnt-1;i>=0;i--){
            n+=pow(2,31-i)*save[i];
        }
        return n;
    }
};