class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        answer = []
        l = text.split(" ")
        n = len(l)
        i = 0
        while i <= n - 3:
            if l[i] == first and l[i + 1] == second:
                answer.append(l[i + 2])
            i += 1
        
        return answer
