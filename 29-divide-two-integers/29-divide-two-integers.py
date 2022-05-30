class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # idea: find largest x = (divisor) * 2^n <= dividend
        #       then iteratively add to quotient when dividend is divisible by x
        # time: O(n), where n is defined in the first line
        # space: O(1)
        if (dividend == -2147483648 and divisor == -1): return 2147483647
        a, b, quotient = abs(dividend), abs(divisor), 0
        for x in range(32)[::-1]:
            if (a >> x) - b >= 0:
                quotient += 1 << x
                a -= b << x
        return quotient if (dividend > 0) == (divisor > 0) else -quotient