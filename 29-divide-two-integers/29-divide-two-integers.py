class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
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