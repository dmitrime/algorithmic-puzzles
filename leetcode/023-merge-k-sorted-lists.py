# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:    
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        nodes = []
        for l in lists:
            while l is not None:
                nodes.append(ListNode(l.val))
                l = l.next
        
        head = current = ListNode(0)
        for x in sorted(nodes, key=lambda x: x.val):
            current.next = x
            current = current.next
        
        return head.next
        
