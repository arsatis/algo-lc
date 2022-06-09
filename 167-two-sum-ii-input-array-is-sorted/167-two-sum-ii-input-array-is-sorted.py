class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        d = {}
        for i, num in enumerate(numbers):
            if target - num in d.keys():
                return [d[target - num] + 1, i + 1]
            d[num] = i