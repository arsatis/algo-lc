class Solution:
    def jump(self, nums: List[int]) -> int:
        l, r, steps = 0, 0, 0
        while r < len(nums) - 1:
            steps += 1
            new_r = r
            for i in range(l, r + 1):
                if i == len(nums): return steps
                new_r = max(new_r, i + nums[i])
            l, r = r + 1, new_r
        return steps