class Solution:
    def isSubstring(self, s1: str, s2: str) -> bool:
        if len(s1) >= len(s2):
            return False
        elif len(s1) < len(s2):
            for i in range(0, len(s2)):
                if s1 == s2[i:i+len(s1)]:
                    return True
        return False
            
    def stringMatching(self, words: List[str]) -> List[str]:
        answer = []
        d = {}
        for i in range(0, len(words)):
            for j in range(0, len(words)):
                if(self.isSubstring(words[i], words[j]) == True): # checo se words[i] eh substring de words[j]
                    if words[i] not in d:
                        d[words[i]] = 1
                        answer.append(words[i])
        
        return answer
