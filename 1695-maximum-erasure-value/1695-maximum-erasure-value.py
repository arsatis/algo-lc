class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        s = set()
        l, r, output, rolling_sum = 0, 0, 0, 0
        while r < len(nums):
            while nums[r] in s:
                s.remove(nums[l])
                rolling_sum -= nums[l]
                l += 1
            s.add(nums[r])
            rolling_sum += nums[r]
            output = max(output, rolling_sum)
            r += 1
        return output