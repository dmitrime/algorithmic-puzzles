class Solution:
    def partition(self, nums, l, r):
        low = l
        while l < r:
            if nums[l] < nums[r]:
                nums[l], nums[low] = nums[low], nums[l]
                low += 1
            l += 1
        nums[low], nums[r] = nums[r], nums[low]
        return low
        
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # shuffle(nums)
        
        k = len(nums) - k
        lo, hi = 0, len(nums)-1
        while lo < hi:
            j = self.partition(nums, lo, hi)
            if j < k:
                lo = j+1
            elif j > k:
                hi = j-1
            else:
                break

        return nums[k]
