# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.ans = float('-inf')
        
    def maxPathSum(self, root: TreeNode) -> int:
        self.helper(root)
        return self.ans
        
    def helper(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        l, r = 0, 0
        if root.left:
            l = max(l, self.helper(root.left))
        if root.right:
            r = max(r, self.helper(root.right))
        
        self.ans = max(self.ans, root.val + l + r)
    
        return root.val + max(l, r)
