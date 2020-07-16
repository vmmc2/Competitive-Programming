class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n >= 0:
            return (x**n)
        else:
            try:
                answer = 1/(x**(n*(-1)))
            except:
                answer = 0
            return answer
