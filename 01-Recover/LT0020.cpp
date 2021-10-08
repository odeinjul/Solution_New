class Solution {
public:
    bool isValid(string s) {
        stack<char> storage;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                storage.push(s[i]);
            }
            else{
                if(!storage.empty()){
                    char temp = storage.top();
                    storage.pop();
                    if(temp == '(' && s[i] == ')')
                        continue;
                    else if(temp == '{' && s[i] == '}')
                        continue;
                    else if(temp == '[' && s[i] == ']')
                        continue;
                    else{
                        return 0;
                    }
                }
                else{
                    return 0;
                }
            
            }
        }
        if(storage.empty())
            return 1;
        else
            return 0;
    }
};