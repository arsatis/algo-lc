class Solution:
    def totalNQueens(self, n: int) -> int:
        self.result = []
        self.DFS(n, [], [], [])
        return len(self.result)
    
    def DFS(self, n, queens, left_diag, right_diag):
        p = len(queens)
        if p == n:
            self.result.append(queens)
            return
        for q in range(n):
            if q not in queens and p - q not in left_diag and p + q not in right_diag: 
                self.DFS(n, queens + [q], left_diag + [p - q], right_diag + [p + q])