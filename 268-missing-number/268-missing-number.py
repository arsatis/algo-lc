class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = set([x for x in range(len(nums) + 1)])
        for num in nums:
            n.remove(num)
        return n.pop()