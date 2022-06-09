class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        d = {}
        for i, num in enumerate(numbers):
            comp = target - num
            if comp in d:
                return [d[comp] + 1, i + 1]
            d[num] = i