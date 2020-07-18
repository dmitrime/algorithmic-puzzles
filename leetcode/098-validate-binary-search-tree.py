# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def validate(self, node, le=float('-inf'), re=float('inf')):
        if node is None:
            return True
        
        if le < node.val < re:
            return self.validate(node.left, le, node.val) and self.validate(node.right, node.val, re)
        
        return False
        
    def isValidBST(self, root: TreeNode) -> bool:
        return self.validate(root)

