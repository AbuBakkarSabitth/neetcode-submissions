#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool isPalindrome(string s){

    string cleaned = "";
    for(int i=0;i<s.size();i++){
        if(isalnum(s[i])){
            char ch = tolower(s[i]);
            cleaned +=ch;
        }
    }
    string reversed = "";
    for(int j=cleaned.size()-1;j>=0;j--){
        reversed = reversed + cleaned[j];
    }
    if(cleaned == reversed){
        return true;
    }
    else{
        return false;
    }




    }
};


