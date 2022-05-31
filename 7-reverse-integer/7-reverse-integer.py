class Solution:
    def reverse(self, x: int) -> int:
        y = int(str(abs(x))[::-1])
        return (-y if x < 0 else y) if y.bit_length() < 32 else 0