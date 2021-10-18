class Solution {
public:
    vector<string> ans;
    int t=('A'-'a');
    vector<string> letterCasePermutation(string s) {
        dfs(s,0);
        return ans;
    }
    void dfs(string s,int ind){
        if(ind == s.size()){
            ans.push_back(s);
            return ;
        }
        if(s[ind]>='0'&&s[ind]<='9'){
            dfs(s,ind+1);
        }
        else{
            char saves = s[ind];
            if(isupper(s[ind]))
                s[ind]=tolower(s[ind]);
            else
                s[ind]=toupper(s[ind]);
            dfs(s,ind+1);
            s[ind]= saves;
            dfs(s,ind+1);
        }
    }
};