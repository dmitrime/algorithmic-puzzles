# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        q = [root]
        result = []
        while q:
            nq = []
            level = [node.val for node in q if node is not None]
            if len(level) > 0: result.append(level[-1])
            q = [n for node in q if node for n in [node.left, node.right]]
        return result
