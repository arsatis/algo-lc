class Solution:
    def reverse(self, x: int) -> int:
        neg, x = (x < 0), abs(x)
        y = int(str(x)[::-1])
        if not neg: return y if y <= 2147483648 else 0
        else: return -y if y < 2147483648 else 0