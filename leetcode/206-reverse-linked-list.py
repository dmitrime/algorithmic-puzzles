# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        temp = ListNode(0)
        
        cur = head
        while cur is not None:
            save = cur.next
            cur.next = temp.next
            temp.next = cur
            cur = save
        
        return temp.next
