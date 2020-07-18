# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstFromPreorder(self, pre: List[int]) -> TreeNode:
        if not pre:
            return None
        else:
            val = pre[0]
            i = 1
            while i < len(pre) and val > pre[i]:
                i += 1
            left = self.bstFromPreorder(pre[1:i])
            right = self.bstFromPreorder(pre[i:])
            return TreeNode(val, left, right)
