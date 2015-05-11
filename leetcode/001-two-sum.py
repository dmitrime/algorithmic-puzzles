class Solution:
    def twoSum(self, nums, target):
        d = {target-n: i for i, n in enumerate(nums)}
        for i, n in enumerate(nums):
            if n in d and d[n] != i:
                return i+1, d[n]+1
