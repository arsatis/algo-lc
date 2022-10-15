class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        minPdt = maxPdt = mx = nums[0]
        for i in range(1, len(nums)):
            if nums[i] < 0:
                minPdt, maxPdt = maxPdt, minPdt
            minPdt = min(nums[i], minPdt * nums[i])
            maxPdt = max(nums[i], maxPdt * nums[i])
            mx = max(mx, maxPdt)
        return mx
        