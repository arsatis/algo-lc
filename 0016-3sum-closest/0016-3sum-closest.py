class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        closest, diff = 0, 20000
        nums.sort()
        for i in range(len(nums)):
            left, right = i + 1, len(nums) - 1
            while left < right:
                curr = nums[i] + nums[left] + nums[right]
                if diff > abs(target - curr):
                    diff = abs(target - curr)
                    closest = curr
                if curr == target: return curr
                elif curr > target: right -= 1
                else: left += 1
        return closest