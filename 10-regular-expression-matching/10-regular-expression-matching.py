class Solution:
    def isMatch(self, s: str, p: str) -> bool:        
        def dp(si, pi):
            if pi >= len(p): return si == len(s)
            if si >= len(s): return pi + 1 < len(p) and p[pi + 1] == '*' and dp(si, pi + 2)
            if (si, pi) not in memo:
                matched = p[pi] == '.' or p[pi] == s[si]
                if pi + 1 < len(p) and p[pi + 1] == '*':
                    memo[(si, pi)] = dp(si, pi + 2) or (matched and dp(si + 1, pi))
                else:
                    memo[(si, pi)] = matched and dp(si + 1, pi + 1)
            return memo[(si, pi)]
        
        memo = {}
        return dp(0, 0)