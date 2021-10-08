// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 1, r = n, p;
        while(l<=r){
            p = (l + r)>>1;
            if(isBadVersion(p)){
                if(!isBadVersion(p-1)){
                    return p;
                }
                else{
                    r = p-1;
                }
            }
            else{
                l = p + 1;
            }
        }
        return p;
    }
};