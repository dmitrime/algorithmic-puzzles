# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def idxSortedArrayToBST(self, nums, start, end):
        if start >= end:
            return None
        
        mid = start + (end - start) // 2
        root = TreeNode(nums[mid])
        root.left = self.idxSortedArrayToBST(nums, start, mid)
        root.right = self.idxSortedArrayToBST(nums, mid+1, end)
        return root
    
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        return self.idxSortedArrayToBST(nums, 0, len(nums))
    
