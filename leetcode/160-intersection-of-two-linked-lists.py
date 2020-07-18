# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return None
        pa, pb = headA, headB
        while pa is not pb:
            pa = pa.next
            pb = pb.next
            
            if pa == pb:
                return pa
            
            if not pa: pa = headB
            if not pb: pb = headA
        
        return pa
