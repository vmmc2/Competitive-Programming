class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # Corner case
        if dividend == -2147483648 and divisor == -1: 
            return 2147483647
        # General case
        a = abs(dividend)
        b = abs(divisor)
        x = 0
        answer = 0
        while a - b >= 0:
            x = 0
            while a - (b << x << 1) >= 0:
                x += 1
            answer += (1 << x)
            a -= (b << x)
        if (dividend > 0 and divisor > 0) or (dividend < 0 and divisor < 0):
            return answer
        else:
            return -answer
