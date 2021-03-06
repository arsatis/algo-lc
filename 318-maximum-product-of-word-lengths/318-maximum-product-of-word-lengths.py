class Solution:
    def maxProduct(self, words: List[str]) -> int:
        # better O(n * c) solution
        d = {}
        for word in words:
            mask = 0
            for c in set(word):
                mask |= 1 << (ord(c) - ord('a'))
            d[mask] = max(d.get(mask, 0), len(word))
        return max([d[x] * d[y] for x in d for y in d if not x & y] or [0])