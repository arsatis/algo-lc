# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        def checkValidity(listnode, treenode):
            if not listnode: return True
            if not treenode or listnode.val != treenode.val: return False
            return checkValidity(listnode.next, treenode.left) or checkValidity(listnode.next, treenode.right)
        
        q = deque([root])
        while q:
            node = q.popleft()
            if node.val == head.val and checkValidity(head, node): return True
            if node.left: q.append(node.left)
            if node.right: q.append(node.right)
        return False
