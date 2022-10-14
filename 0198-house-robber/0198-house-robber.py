class Solution:
    def rob(self, nums: List[int]) -> int:
        prev1, prev2 = 0, 0
        for x in nums:
            prev2 = max(prev1, prev2 + x)
            prev1, prev2 = prev2, prev1
        return prev1