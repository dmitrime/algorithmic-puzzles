"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def helper(self, node, clone, seen, m):
        if not node:
            return
        if node.val in seen:
            return
        seen[node.val] = True
        for nei in node.neighbors:
            if nei.val not in m:
                m[nei.val] = Node(nei.val)
            clone.neighbors.append(m[nei.val])
            self.helper(nei, clone.neighbors[-1], seen, m)
        
        
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None   
        clone = Node(node.val)
        self.helper(node, clone, {}, {node.val: clone})
        return clone
