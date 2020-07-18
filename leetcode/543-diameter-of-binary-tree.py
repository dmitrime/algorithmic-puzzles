# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.ans = 0
        
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        def depth(root):
            if not root:
                return 0
            l, r = depth(root.left), depth(root.right)
            self.ans = max(self.ans, l+r)
            return 1 + max(l, r)
        
        depth(root)
        return self.ans
