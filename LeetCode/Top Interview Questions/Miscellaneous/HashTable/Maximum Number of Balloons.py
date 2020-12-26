from collections import defaultdict

class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        balloon = {
            'b' : 1,
            'a' : 1,
            'l' : 2,
            'o' : 2,
            'n' : 1,
        }
        d = defaultdict(int)
        for char in text:
            if char not in d:
                d[char] = 1
            else:
                d[char] += 1
        minimo1 = min(d['a'], min(d['b'], d['n']))
        minimo2 = min(d['l'], d['o'])
        if minimo1 * 2 <= minimo2:
            return minimo1
        else:
            if minimo2 % 2 == 0:
                return minimo2//2
            else:
                return (minimo2 - 1)//2
        
