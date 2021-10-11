class Solution {
public:
    string reverseWords(string s) {
        int r0=-2,l0=0;
        for(int i = 0; i < s.size(); i++){
            if(s[i]==' '){
                l0 = r0 + 2;
                r0 = i - 1;
                int l = l0, r = r0;
                while(l<r){
                    swap(s[l],s[r]);
                    l++; r--;
                }
            }
        }
        l0 = r0 + 2;
        r0 = s.size()-1;
        int l = l0, r = r0;
            while(l<r){
                swap(s[l],s[r]);
                l++; r--;
        }
        return s;
    }
};