class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left, right = 0, 0
        max_len = 0
        curr = set()
        while right < len(s):
            if s[right] not in curr:
                curr.add(s[right])
                max_len = max(max_len, len(curr))
            else:
                while s[right] in curr:
                    curr.remove(s[left])
                    left += 1
                curr.add(s[right])
            right += 1
        return max_len