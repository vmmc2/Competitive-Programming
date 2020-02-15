class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 2:
            return 0
        isPrime = [True] * n
        isPrime[0] = False
        isPrime[1] = False
        for i in range(2, n):
            if (isPrime[i] == True) and (i*i <= n):
                for j in range(i*i, n, i):
                    isPrime[j] = False
        answer = 0
        for element in isPrime:
            if element == True:
                answer += 1
        return answer
