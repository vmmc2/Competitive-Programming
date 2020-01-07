class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0:
            return []
        dp = []
        #montando a table
        for i in range(1, numRows + 1):
            dp.append([0]*i)
        dp[0][0] = 1
        if numRows > 1:
            dp[1][0] = 1
            dp[1][1] = 1
            for i in range(2, numRows):
                for j in range(0, len(dp[i])):
                    if j == 0 or j == len(dp[i]) - 1:
                        dp[i][j] = 1
                    else:
                        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
        return dp
