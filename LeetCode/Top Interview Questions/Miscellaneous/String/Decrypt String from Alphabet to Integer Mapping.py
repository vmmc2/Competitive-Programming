# Time Complexity: O(|s|)
# Space Complexity: O(26) + O(|s|) = O(1) + O(|s|) = O(|s|)

class Solution:
    def freqAlphabets(self, s: str) -> str:
        answer = ""
        d = {
            '1' : 'a', '2' : 'b', '3' : 'c', '4' : 'd', '5' : 'e', '6' : 'f', '7' : 'g', 
            '8' : 'h', '9' : 'i', '10#' : 'j', '11#' : 'k', '12#' : 'l', "13#" : 'm',
            '14#' : 'n', "15#" : 'o', '16#' : 'p', "17#" : 'q', "18#" : 'r', "19#" : 's',
            '20#' : 't', "21#" : 'u', "22#" : 'v', "23#" : 'w', "24#" : 'x', "25#" : 'y',
            "26#" : 'z'
        }
        if len(s) <= 2:
            for i in range(0, 2):
                answer += d[s[i]]
        else:
            i = 0
            n = len(s)
            while i < n:
                if i + 2 < n and s[i + 2] == '#':
                    answer += d[s[i:i+3]]
                    i += 3
                else:
                    answer += d[s[i]]
                    i += 1
        return answer
