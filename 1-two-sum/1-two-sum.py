class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        s = {}
        for i in range(len(nums)):
            c = target - nums[i]
            if c in s:
                return [i, s[c]]
            s[nums[i]] = i