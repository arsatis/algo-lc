class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0: return False
        y = str(x)
        for i in range(len(y) // 2):
            if y[i] != y[len(y) - i - 1]:
                return False
        return True