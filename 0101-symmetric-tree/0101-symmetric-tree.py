# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def helper(left, right):
            if not left or not right: return not left and not right
            return left.val == right.val and helper(left.left, right.right) and helper(left.right, right.left)
        
        if not root: return True
        if not root.left or not root.right: return not root.left and not root.right
        return helper(root.left, root.right)