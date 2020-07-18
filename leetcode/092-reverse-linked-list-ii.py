# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        if head is None:
            return None
        
        temp = ListNode(0)
        temp.next = head
        
        prev = temp
        for _ in range(m-1):
            prev = prev.next
            
        start = prev.next 
        after = start.next
        for _ in range(n-m):
            start.next = after.next
            after.next = prev.next
            prev.next = after
            after = start.next
            
        return temp.next

