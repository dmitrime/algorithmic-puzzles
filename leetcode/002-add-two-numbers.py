# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:

    def extract_number(self, l):
        n, mul = 0, 1
        while l != None:
            n += mul * l.val
            mul *= 10
            l = l.next
        return n

    def pack_number(self, n):
        l = ListNode(n % 10)
        n /= 10
        ln = l
        while n > 0:
            ln.next = ListNode(n % 10)
            ln = ln.next
            n /= 10

        return l
        
    def addTwoNumbers(self, l1, l2):
        return self.pack_number(self.extract_number(l1)+self.extract_number(l2))
