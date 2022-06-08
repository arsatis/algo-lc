class Solution:
    def removePalindromeSub(self, s: str) -> int:
        def zip_iter():
            i, j = 0, len(s) - 1
            while i < len(s):
                yield (s[i], s[j])
                i += 1
                j -= 1
                
        return 1 if all(x == y for x, y in zip_iter()) else 2