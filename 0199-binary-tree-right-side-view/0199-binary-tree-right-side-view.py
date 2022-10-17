# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root: return []
        view = []
        q = collections.deque([root])
        while len(q):
            size = len(q)
            view.append(q[-1].val)
            for i in range(size):
                nextnode = q.popleft()
                if nextnode.left: q.append(nextnode.left)
                if nextnode.right: q.append(nextnode.right)
        return view