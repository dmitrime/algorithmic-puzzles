class Solution:
    def getPos(self, nums, i):
        if i < 0 or i >= len(nums):
            return 1
        return nums[i]
    
    def getMax(self, nums, start, end, dp):
        if start > end:
            return 0
        if (start, end) in dp:
            return dp[(start, end)]
        
        sofar = 0
        for i in range(start, end+1):
            mul = self.getPos(nums, start-1) * nums[i] * self.getPos(nums, end+1)
            before = self.getMax(nums, start, i-1, dp)
            after = self.getMax(nums, i+1, end, dp)
            sofar = max(sofar, before + mul + after )
            
        dp[(start, end)] = sofar
        return dp[(start, end)]
    
    def maxCoins(self, nums: List[int]) -> int:
         return self.getMax(nums, 0, len(nums)-1, {})
