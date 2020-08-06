class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        # Treating corner case first:
        if len(strs) == 0:
            return ""
        # Solving the problem for the general cases:
        maxpreflen = None
        base = ""
        for element in strs:
            if maxpreflen == None:
                maxpreflen = len(element)
                base = element
            else:
                if len(element) < maxpreflen:
                    maxpreflen = len(element)
                    base = element
        answer = ""
        for i in range(1, maxpreflen + 1):
            davez = base[0:i]
            deuruim = False
            for j in range(0, len(strs)):
                if davez != strs[j][0:i]:
                    deuruim = True
                    break
            if deuruim == True:
                break
            answer = davez
        return answer
            
            
