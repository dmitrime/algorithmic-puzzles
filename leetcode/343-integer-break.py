class Solution:
    def integerBreak(self, n: int) -> int:
        dp = [0] * (n+1)
        dp[0] = 1
        mx = 0
        for i in range(1, n):
            for j in range(i, n+1):
                dp[j] = max(dp[j], dp[j-i] * i)
                if n == j and dp[j] > mx:
                    mx = dp[j] 
        return dp[j]
        
