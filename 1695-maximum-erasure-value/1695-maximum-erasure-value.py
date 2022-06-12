class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        s = set()
        l, r, output, currSum = 0, 0, 0, 0
        while r < len(nums):
            while nums[r] in s:
                s.remove(nums[l])
                currSum -= nums[l]
                l += 1
            s.add(nums[r])
            currSum += nums[r]
            output = max(output, currSum)
            r += 1
        return output