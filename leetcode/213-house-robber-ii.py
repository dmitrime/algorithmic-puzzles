class Solution:
    def solve(self, nums):
        dp = [0] * (len(nums)+1)
        for i in range(1, len(dp)):
            if i == 1:
                dp[i] = nums[i-1]
            else:
                dp[i] = max(nums[i-1] + dp[i-2], dp[i-1])
        return dp[-1]
        
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0: return 0
        if len(nums) == 1: return nums[0]
        
        nums1, nums2 = nums[:-1], nums[1:]
        return max(self.solve(nums1), self.solve(nums2))
