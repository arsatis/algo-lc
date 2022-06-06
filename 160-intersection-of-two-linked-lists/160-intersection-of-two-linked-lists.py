# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        setA, setB = set([headA]), set([headB])
        while headA != None or headB != None:
            if headA:
                if headA in setB: return headA
                headA = headA.next
                setA.add(headA)
            if headB:
                if headB in setA: return headB
                headB = headB.next
                setB.add(headB)
        return None