# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        cur = slow = head
        while cur and cur.next:
            cur = cur.next.next
            slow = slow.next
            if cur == slow:
                while head != slow:
                    head = head.next
                    slow = slow.next
                return head
        
        return None
