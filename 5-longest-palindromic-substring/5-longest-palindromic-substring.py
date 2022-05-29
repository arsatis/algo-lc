class Solution:
    def longestPalindrome(self, s: str) -> str:
        output = ""
        for i in range(2 * len(s) - 1): # O(n)
            left, right = i // 2, (i + 1) // 2
            while left >= 0 and right < len(s): # O(n)
                if s[left] != s[right]:
                    break
                if right - left + 1 > len(output):
                    output = s[left:right + 1]
                left -= 1
                right += 1
            if 2 * len(s) - i - 1 < len(output):
                break
        return output