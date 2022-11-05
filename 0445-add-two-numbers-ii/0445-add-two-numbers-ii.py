# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        s1, s2 = collections.deque(), collections.deque()
        while l1:
            s1.append(l1.val)
            l1 = l1.next
        while l2:
            s2.append(l2.val)
            l2 = l2.next

        curr = None
        carry = 0
        while s1 or s2:
            if s1: carry += s1.pop()
            if s2: carry += s2.pop()
            tmp = ListNode(carry % 10)
            tmp.next, curr = curr, tmp
            carry //= 10
        if carry:
            tmp = ListNode(carry)
            tmp.next, curr = curr, tmp
        return curr
