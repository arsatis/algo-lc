class Solution:
    def convert(self, s: str, numRows: int) -> str:
        # Idea: use buckets and trace the zigzag movement
        # Time: O(n), two passes
        # Space: O(n), for the buckets
        if numRows == 1 or numRows >= len(s): return s

        buckets = list(s[:numRows])
        idx, step = numRows - 2, -1
        for c in s[numRows:]: # O(n)
            buckets[idx] += c # >O(1)
            if idx == 0:
                step = 1
            elif idx == numRows -1:
                step = -1
            idx += step
        return ''.join(buckets) # O(n)