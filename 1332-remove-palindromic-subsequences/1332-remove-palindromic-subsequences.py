class Solution:
    def removePalindromeSub(self, s: str) -> int:
        def generator():
            i, j = 0, len(s) - 1
            while i < j:
                yield (s[i], s[j])
                i += 1
                j -= 1
        return 1 if all(x == y for x, y in generator()) else 2