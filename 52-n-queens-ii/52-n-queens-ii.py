class Solution:
    def totalNQueens(self, n: int) -> int:
        def DFS(queens, left_diag, right_diag):
            p = len(queens)
            if p == n:
                result.append(queens)
                return
            for q in range(n):
                if q not in queens and p - q not in left_diag and p + q not in right_diag: 
                    DFS(queens + [q], left_diag + [p - q], right_diag + [p + q])
        result = []
        DFS([], [], [])
        return len(result)