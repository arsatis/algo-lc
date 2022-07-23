class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        sorted_list = [nums[-1]]
        for i in range(n - 2, -1, -1):
            idx = bisect.bisect_left(sorted_list, nums[i])
            ans[i] = idx
            bisect.insort_left(sorted_list, nums[i])
        return ans