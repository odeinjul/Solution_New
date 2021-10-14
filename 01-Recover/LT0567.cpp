class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        int s1m[26]={0},s2m[26]={0};
        for(int i = 0; i < s1.length(); i++){
            s1m[s1[i]-'a']++;
            s2m[s2[i]-'a']++;
        }
        for(int i = 0; i < s2.length() - s1.length();i++){
            if(matches(s1m, s2m))
                return true;
            s2m[s2[i+s1.length()]-'a']++;
            s2m[s2[i]-'a']--;
            
        }
        return (matches(s1m, s2m));
    }
    bool matches(int s1m[], int s2m[]){
        for(int i = 0; i < 26; i++){
            if(s1m[i] != s2m[i])
                return false;
        }
        return true;
    }
};