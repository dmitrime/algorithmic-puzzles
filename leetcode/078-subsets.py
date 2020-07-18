class Solution:
    def subsetsX(self, nums: List[int]) -> List[List[int]]:
        subs = [[]] 
        for n in nums:
            subs += [j + [n] for j in subs]
        return subs
    
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        def rec(idx, sub):
            result.append(sub)
            for i in range(idx, len(nums)):
                rec(i+1, sub + [nums[i]])
        rec(0, [])
        return result
