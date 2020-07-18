class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        result = 0
        count = defaultdict(int)
        count[0] = 1
        sum = 0
      
        for i in range(len(nums)):
            sum += nums[i]
            result += count[sum-k]
            count[sum] += 1
                    
        return result
