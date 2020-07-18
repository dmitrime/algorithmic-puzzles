class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        sofar = smax = nums[0]
        for i in range(1, len(nums)):
            sofar = max(nums[i], sofar+nums[i])
            smax = max(smax, sofar)
            
        return smax
