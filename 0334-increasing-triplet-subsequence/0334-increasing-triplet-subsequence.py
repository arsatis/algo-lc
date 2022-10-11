class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        first, second = math.inf, math.inf
        for x in nums:
            if x <= first:
                first = x
            elif x <= second:
                second = x
            else:
                return True
        return False