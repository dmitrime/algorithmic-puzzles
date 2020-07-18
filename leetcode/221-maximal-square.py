class Solution:
    def maximalSquare(self, m: List[List[str]]) -> int:
        if not m or not m[0]:
            return 0
        dp = [[0]*(len(m[0])+1) for _ in range(len(m)+1)]
        least = 0
        for i in range(1, len(m)+1):
            for j in range(1, len(m[0])+1):
                if m[i-1][j-1] == "1":
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) + 1
                    least = max(least, dp[i][j])
                    
        return least*least
