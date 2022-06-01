import re

class Solution:
    def myAtoi(self, s: str) -> int:
        r = re.match(r'\s*[+-]?\d+', s)
        if not r:
            return 0
        r = int(r.group(0))
        return -2147483648 if r < -2147483648 else (r if r < 2147483647 else 2147483647)