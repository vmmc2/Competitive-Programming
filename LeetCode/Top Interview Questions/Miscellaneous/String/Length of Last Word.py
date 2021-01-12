class Solution:
    def isAllSpaces(self, s: str) -> bool:
        allSpaces = True
        for i in range(0, len(s)):
            if s[i] != " ":
                allSpaces = False
                break
        return allSpaces
    def lengthOfLastWord(self, s: str) -> int:
        answer = 0
        n = len(s)
        left = n - 1
        
        if self.isAllSpaces(s) == True:
            return answer
        
        while left >= 0 and s[left] == " ":
            left -= 1
        right = left - 1
        while right >= 0 and s[right] != " ":
            right -= 1
        answer = left - right
        
        return answer
