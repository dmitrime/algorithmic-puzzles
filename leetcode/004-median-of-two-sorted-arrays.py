class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)
        
        X, Y = len(nums1), len(nums2)
        
        lo, hi = 0, X
        while lo <= hi:
            partX = (hi+lo) // 2
            partY = (X+Y+1) // 2 - partX
            
            maxLeftX = float('-inf') if partX == 0 else nums1[partX-1]
            minRightX = float('inf') if partX == X else nums1[partX]
            
            maxLeftY = float('-inf') if partY == 0 else nums2[partY-1]
            minRightY = float('inf') if partY == Y else nums2[partY]
            
            # print(maxLeftX, minRightY, ' x ', minRightX, maxLeftY)
            if maxLeftX <= minRightY and minRightX >= maxLeftY:
                if (X+Y) % 2 == 1:
                    return max(maxLeftX, maxLeftY)
                else:
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0
            elif maxLeftX > minRightY:
                hi = partX-1
            else:
                lo = partX+1
                
        return -1
                
