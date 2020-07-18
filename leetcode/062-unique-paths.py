class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [1] * n
        prev = [1] * n
        for i in range(1, m):
            for j in range(1, n):
                dp[j] = prev[j] + dp[j-1]
            prev = dp
        
        return dp[n-1]
