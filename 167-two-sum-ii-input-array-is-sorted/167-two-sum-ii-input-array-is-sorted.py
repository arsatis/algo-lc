class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1
        while left < right:
            both = numbers[left] + numbers[right]
            if both < target:
                left += 1
            elif both > target:
                right -= 1
            else:
                return [left + 1, right + 1]
        return None