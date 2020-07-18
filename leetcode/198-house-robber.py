class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [0] * (len(nums) + 1)
        for i in range(1, len(dp)):
            if i == 1:
                dp[i] = nums[i-1]
            else:
                dp[i] = max(nums[i-1] + dp[i-2], dp[i-1])
        
        return dp[len(nums)]
