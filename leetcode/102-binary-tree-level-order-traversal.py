# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        result, q = [], [root]
        while q:
            level, nq = [], []
            for node in q:
                if node is not None:
                    level.append(node.val)
                    nq.extend([node.left, node.right])
            q = nq
            if len(level) > 0:
                result.append(level)
        return result
                    
