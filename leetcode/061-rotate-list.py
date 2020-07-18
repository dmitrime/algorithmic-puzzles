# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        l = 0
        cur = head
        while cur:
            cur = cur.next
            l += 1
        k = 0 if l == 0 else k % l
        
        if l <= 1 or k == 0: return head
        
        temp = ListNode(0)
        prev, cur = None, head
        for n in range(l-k):
            prev = cur
            cur = cur.next
            
        temp.next = cur
        prev.next = None
        
        while cur.next:
            cur = cur.next
        cur.next = head
        
        return temp.next
