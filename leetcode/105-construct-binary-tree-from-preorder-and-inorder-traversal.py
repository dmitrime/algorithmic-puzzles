# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def helper(self, pre, ino):
        if len(ino) == 0:
            return None
        
        root = TreeNode(pre.pop(0))
        sep = ino.index(root.val)
        root.left = self.helper(pre, ino[:sep])
        root.right = self.helper(pre, ino[sep+1:])
        
        return root
        
    def buildTree(self, pre: List[int], ino: List[int]) -> TreeNode:
        return self.helper(pre, ino)

        
