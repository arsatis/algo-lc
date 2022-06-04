class Solution:
    def isPalindrome(self, x: int) -> bool:
        # should be fastest because string comp in py is amortized O(1)
        s = str(x)
        return s[:1 + len(s) // 2] == s[::-1][:1 + len(s) // 2]