class Solution:
    def rob(self, nums: List[int]) -> int:
        prev1, prev2 = 0, 0
        for x in nums:
            tmp = max(prev1, prev2 + x)
            prev2 = prev1
            prev1 = tmp
        return prev1