# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    def __init__(self):
        self.temp = None
 
    def flatten(self, root: TreeNode) -> None:
        if root is None:
            return None
        
        self.flatten(root.right)        
        self.flatten(root.left)

        root.right = self.temp
        self.temp = root
        root.left = None
        
        return root
