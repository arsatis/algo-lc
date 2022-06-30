class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        # # dumb algorithm
        # median = sorted(nums)[len(nums) // 2]
        # return sum(abs(num - median) for num in nums)
    
        # using bitwise inverse
        nums.sort()
        return sum(nums[~i] - nums[i] for i in range(len(nums) // 2))