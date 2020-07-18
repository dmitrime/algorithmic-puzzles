"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return None
        
        m = dict()
        
        cur = head
        while cur:
            m[cur] = Node(cur.val)
            cur = cur.next
            
        cur = head
        while cur:
            m[cur].next = m.get(cur.next, None)
            m[cur].random = m.get(cur.random, None)
            cur = cur.next
        
        return m[head]
