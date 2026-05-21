class Solution {
public:

    // Encode list of strings to single string
    string encode(vector<string>& strs) {
        string result = "";

        for(string &word : strs){
            result += to_string(word.size()) + "#" + word;
        }

        return result;
    }

    // Decode single string to list of strings
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while(i < s.size()){
            // 1. Find length
            int j = i;
            while(s[j] != '#'){
                j++;
            }

            int length = stoi(s.substr(i, j - i));

            // 2. Move to word start
            j++; // skip '#'

            // 3. Extract word
            string word = s.substr(j, length);
            result.push_back(word);

            // 4. Move pointer
            i = j + length;
        }

        return result;
    }
};