class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>tCount;
        unordered_map<char,int>window;
        for(char c:t){
            tCount[c]++;
        }
        int have=0;
        int need = tCount.size();
        int left =0;
        int minLen = INT_MAX;
        int start =0;
        for(int right=0;right<s.size();right++){
            char c = s[right];
            window[c]++;
            if(tCount.count(c) && window[c]==tCount[c]){
                have++;
            }
            while(have == need){
                if((right-left+1)<minLen){
                    minLen = right-left+1;
                    start = left;

                }
                window[s[left]]--;
                if(tCount.count(s[left])&& window[s[left]] < tCount[s[left]]){
                    have--;
                }
                left++;
            
        }
        }
        if(minLen == INT_MAX) return "";
        return s.substr(start,minLen);
    }
};

