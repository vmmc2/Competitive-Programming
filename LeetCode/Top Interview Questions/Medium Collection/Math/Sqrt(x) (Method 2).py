class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0:
            return 0
        #Abordagem 2: Resolvendo o problema com busca binaria.
        low = 1
        high = x
        answer = 1
        while low <= high:
            mid = (low + high)//2
            if mid * mid > x:
                high = mid - 1
            elif mid * mid <= x:
                answer = mid
                low = mid + 1
        return answer
