class Solution:
    def maxPower(self, s: str) -> int:
        left = 0
        n = len(s)
        answer = -1
        curr = 0
        
        prev = '-'
        while left < n:
            if prev == '-':
                curr += 1
                prev = s[left]
            else:
                if s[left] != prev:
                    answer = max(answer, curr)
                    curr = 1
                    prev = s[left]
                else:
                    curr += 1
            left += 1
        answer = max(answer, curr)
        return answer
