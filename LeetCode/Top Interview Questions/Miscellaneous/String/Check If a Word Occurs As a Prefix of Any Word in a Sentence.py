# Time Complexity = O(n*|s|)

class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        answer = -1
        sz = len(searchWord)
        l = sentence.split(" ")
        for i in range(0, len(l)):
            if sz <= len(l[i]) and searchWord == l[i][0:sz]:
                answer = i + 1
                break
        return answer
