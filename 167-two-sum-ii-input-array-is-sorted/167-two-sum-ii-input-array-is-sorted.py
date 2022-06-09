class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        d = {}
        for i, num in enumerate(numbers):
            c = target - num
            if c in d: return [d[c] + 1, i + 1]
            d[num] = i