from collections import counter

class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        l1 = A.split(" ")
        l2 = B.split(" ")
        dA = Counter(l1)
        dB = Counter(l2)
        answer = []
        
        for k,v in dA.items():
            if v == 1 and k not in dB:
                answer.append(k)
        for k,v in dB.items():
            if v == 1 and k not in dA:
                answer.append(k)
        
        return answer
        
        
