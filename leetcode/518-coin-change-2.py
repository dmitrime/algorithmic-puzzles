class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [0] * (amount+1)
        dp[0] = 1
        for c in coins:
            for a in range(amount+1):
                if c <= a:
                    dp[a] += dp[a-c]
        
        return dp[amount]
