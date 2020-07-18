# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head):
        temp = ListNode(0)
        cur = head
        while cur is not None:
            save = cur.next
            cur.next = temp.next
            temp.next = cur
            cur = save
        return (temp.next, head)
        
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        newHead = None
        kth = start = head
        prev = None
        while kth is not None:
            stop = False
            for _ in range(k-1):
                if kth is not None:
                    kth = kth.next

            if kth is not None:
                save = kth.next
                kth.next = None
                head, last = self.reverseList(start)
                if newHead is None:
                    newHead = head
                kth = start = last.next = save
                if prev:
                    prev.next = head
                prev = last
        
        return newHead
