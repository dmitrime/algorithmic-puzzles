class Solution:
    def bsearch(self, nums, t):
        lo, hi = 0, len(nums)-1
        while lo <= hi:
            mid = lo + (hi-lo) // 2
            
            if nums[mid] == t:
                return True
            elif nums[mid] > t:
                hi = mid -1
            else:
                lo = mid + 1
        
        return False
        
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix:
            return False
        
        i, j = 0, len(matrix[0])-1
        while i < len(matrix) and j >= 0:
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] > target:
                j -= 1
            else:
                i += 1
        
        return False
