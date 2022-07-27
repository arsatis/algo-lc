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
        head_list = []
        while head:
            head_list.append(head.val)
            head = head.next
        m = len(head_list)
        seen = []
        def dfs(node):
            if node == None:
                return False
            seen.append(node.val)
            if seen[-m:] == head_list:
                return True
            elif dfs(node.left) or dfs(node.right):
                return True
            seen.pop()
            return False
        
        return dfs(root)
