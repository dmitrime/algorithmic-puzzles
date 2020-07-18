# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    def __init__(self):
        self.map = None
    
    def getIndex(self, ino):
        self.map = {k: i for i, k in enumerate(ino)}
    
    def helper(self, ino, post):
        if not ino or not post:
            return None
        
        root = TreeNode(post.pop())
        idx = self.map[root.val]
        root.right = self.buildTree(ino[idx+1:], post)
        root.left = self.buildTree(ino[:idx], post)
        
        return root
    
    def buildTree(self, ino: List[int], post: List[int]) -> TreeNode:
        self.getIndex(ino)
        return self.helper(ino, post)
