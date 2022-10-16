class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(s) < len(t): return ""        
        left = 0
        right = 0
        need = Counter(t)
        missing = len(t)
        minLeft, minRight = 0, 0
        
        while right < len(s):
            missing -= (need[s[right]] > 0)
            need[s[right]] -= 1
            right += 1
            if not missing:
                while left < right and need[s[left]] < 0:
                    need[s[left]] += 1
                    left += 1
                if not minRight or minRight - minLeft > right - left:
                    minLeft, minRight = left, right
            
        return s[minLeft:minRight]
            