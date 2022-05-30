class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # idea: find largest x = (divisor) * 2^n <= dividend
        #       then iteratively add to quotient when dividend is divisible by x
        # time: O(n), where n is as stated in the first line
        # space: O(1)
        neg = (dividend < 0) ^ (divisor < 0)
        divisor, dividend = abs(divisor), abs(dividend)
        
        # find largest (divisor) * 2^n <= dividend
        curr, n = divisor, 1
        while dividend >= (curr << 1):
            curr <<= 1
            n <<= 1
            
        # repeatedly add current_quotient
        quotient = 0
        while dividend >= divisor:
            if dividend >= curr:
                dividend -= curr
                quotient += n
            curr >>= 1
            n >>= 1
            
        return min(2147483647, max(-quotient if neg else quotient, -2147483648))