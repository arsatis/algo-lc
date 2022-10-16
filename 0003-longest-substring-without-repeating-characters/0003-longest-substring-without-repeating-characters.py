class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = counter = maxLen = 0
        for right in range(len(s)):
            while counter & (1 << ord(s[right])):
                counter ^= (1 << ord(s[left]))
                left += 1
            counter ^= (1 << ord(s[right]))
            maxLen = max(maxLen, right - left + 1)
        return maxLen
            