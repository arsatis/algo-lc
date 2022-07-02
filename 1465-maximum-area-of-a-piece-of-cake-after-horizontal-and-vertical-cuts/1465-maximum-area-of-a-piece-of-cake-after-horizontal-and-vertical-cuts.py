class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        hcurr, vcurr = h, w
        h_max_diff, v_max_diff = 0, 0
        for i in sorted(horizontalCuts + [0], reverse=True):
            h_max_diff = max(h_max_diff, hcurr - i)
            hcurr = i
        for i in sorted(verticalCuts + [0], reverse=True):
            v_max_diff = max(v_max_diff, vcurr - i)
            vcurr = i
        return (h_max_diff * v_max_diff) % 1000000007