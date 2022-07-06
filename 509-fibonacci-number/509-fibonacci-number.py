class Solution:
    def fib(self, n: int) -> int:
        arr = [0, 1]
        for i in range(31):
            arr.append(arr[-1] + arr[-2])
        return arr[n]