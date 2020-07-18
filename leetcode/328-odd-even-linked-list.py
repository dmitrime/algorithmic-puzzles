# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        s1, s2 = ListNode(0), ListNode(0)
        odd, even = s1, s2
        
        while head:
            odd.next = head
            even.next = head.next
            
            odd = odd.next
            even = even.next
            
            if head.next:
                head = head.next.next
            else:
                head = head.next

        
        odd.next = s2.next
        return s1.next
