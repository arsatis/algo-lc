class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        # dumb algorithm
        median = sorted(nums)[len(nums) // 2]
        return sum(abs(num - median) for num in nums)