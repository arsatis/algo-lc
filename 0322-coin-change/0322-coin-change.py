class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [0] + [-1] * amount
        for i in range(1, amount + 1):
            val = 100000
            for coin in coins:
                if i - coin >= 0 and dp[i - coin] != -1:
                    val = min(val, 1 + dp[i - coin])
            if val != 100000: dp[i] = val
        return dp[-1]