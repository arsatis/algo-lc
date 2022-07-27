# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        curr = TreeNode()
        stack = deque([root]) if root else None
        while stack:
            temp = stack.pop()
            if temp.right: stack.append(temp.right)
            if temp.left: stack.append(temp.left)
            curr.right = temp
            curr.left = None
            curr = curr.right            
        