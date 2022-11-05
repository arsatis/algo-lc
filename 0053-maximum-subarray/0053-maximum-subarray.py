class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        mx, curr = -10001, 0
        for x in nums:
            curr = max(x, curr + x)
            mx = max(curr, mx)
        return mx
