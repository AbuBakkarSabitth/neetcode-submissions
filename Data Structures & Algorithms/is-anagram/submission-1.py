class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if(len(s)!= len(t)):
            return False
        s= list(s)
        for i in range(0,len(t)):
            found = False
            for j in range(0,len(s)):
                if(t[i]==s[j]):
                    found = True
                    s.pop(j)
                    break
            if not found:
                return False
        return len(s) == 0
