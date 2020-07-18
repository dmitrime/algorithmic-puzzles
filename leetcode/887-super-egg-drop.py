class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        dp = [[0] * (N+1) for _ in range(K+1)]
        
        for j in range(N+1):
            dp[1][j] = j
            
        for e in range(2, K+1):
            for f in range(1, N+1):
                dp[e][f] = min([1 + max(dp[e-1][k-1], dp[e][f-k]) for k in range(1, f+1)])

        return dp[K][N]
