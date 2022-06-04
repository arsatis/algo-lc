class Solution:
    def isPalindrome(self, x: int) -> bool:
        # should be fastest because string comp in py is amortized O(1)
        s = str(x)
        return s == s[::-1]