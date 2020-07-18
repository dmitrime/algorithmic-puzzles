"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        if root is None:
            return []
        ret = []
        for ch in root.children:
            ret = ret + self.postorder(ch)
        return ret + [root.val]
