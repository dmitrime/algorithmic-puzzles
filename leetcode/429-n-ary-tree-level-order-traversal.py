"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        result = []
        if not root:
            return result
        
        result.append([root.val])
        q = [root]
        while q:
            lvl = [n for node in q for n in node.children if n]
            if lvl:
                result.append([n.val for n in lvl])
            q = lvl
        
        return result
