class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,int>mp;
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                if(st.top() != mp[s[i]]) return false;
            
            st.pop();
            }
        }
        return st.empty();
    }
        };
        

