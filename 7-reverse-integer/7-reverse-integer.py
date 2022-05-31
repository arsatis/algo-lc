class Solution:
    def reverse(self, x: int) -> int:
        sign = [1,-1][x < 0]
        y = sign * int(str(abs(x))[::-1])
        return y if -2147483647 < y < 2147483648 else 0