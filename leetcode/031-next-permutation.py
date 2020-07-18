class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        i = len(nums)-1
        
        # find longest non-increasing suffix from the right
        while i > 0 and nums[i-1] >= nums[i]:
            i -= 1
            
        # no greater permutations
        if i == 0:
            nums.reverse()
            return
        
        pivot = i-1
        j = len(nums)-1
        
        # find rightmost element greater than pivot
        while nums[pivot] >= nums[j]:
            j -= 1
            
        # swap pivot and found element
        nums[pivot], nums[j] = nums[j], nums[pivot]
        
        # reverse the suffix after pivot
        l, r = pivot+1, len(nums)-1
        while l < r:
            nums[l], nums[r] = nums[r], nums[l]
            l += 1
            r -= 1
