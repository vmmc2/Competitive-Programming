class Solution:
    def countSegments(self, s: str) -> int:
        counter = 0
        for i in range(0, len(s)):
            if i < len(s) - 1 and s[i] != " " and s[i + 1] == " ":
                counter += 1
            if i == len(s) - 1 and s[i] != " ":
                counter += 1
        return counter
