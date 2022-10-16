class Solution:
    def minWindow(self, s: str, t: str) -> str:
        left = right = minLeft = 0
        minRight = 100001
        count = len(t)
        counter = [0] * 64
        for c in t: counter[ord(c) - ord('A')] += 1
        while right < len(s):
            if counter[ord(s[right]) - ord('A')] > 0: count -= 1
            counter[ord(s[right]) - ord('A')] -= 1
            right += 1
            if count == 0:
                while counter[ord(s[left]) - ord('A')] < 0:
                    counter[ord(s[left]) - ord('A')] += 1
                    left += 1
                if minRight - minLeft > right - left:
                    minRight, minLeft = right, left
        return s[minLeft : minRight] if minRight != 100001 else ""
            