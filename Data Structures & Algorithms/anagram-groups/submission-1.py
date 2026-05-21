class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        result = []

        used = [False] * len(strs)
        for i in range(len(strs)):
            if used[i]:
                continue
            list1 = [strs[i]]
            used[i] =  True
            for j in range(i+1,len(strs)):
                if not used[j] and sorted(strs[i]) == sorted(strs[j]):
                    list1.append(strs[j])
                    used[j] = True
            result.append(list1)
        if(len(strs)==0):
            return [[""]]
        return result
                

                
        