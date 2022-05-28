# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        curr = dummy = ListNode()
        carryover = 0
        while l1 and l2:
            total = l1.val + l2.val + carryover
            carryover = total // 10
            curr.next = ListNode(total % 10)
            curr = curr.next
            l1 = l1.next
            l2 = l2.next
        rem = l1 if not l2 else l2
        while rem:
            total = rem.val + carryover
            carryover = total // 10
            curr.next = ListNode(total % 10)
            curr = curr.next
            rem = rem.next
        if carryover:
            curr.next = ListNode(carryover)
        return dummy.next