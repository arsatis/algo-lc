class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0: return False
        y, ylen = str(x), len(str(x))
        for i in range(ylen // 2):
            if y[i] != y[ylen - i - 1]:
                return False
        return True