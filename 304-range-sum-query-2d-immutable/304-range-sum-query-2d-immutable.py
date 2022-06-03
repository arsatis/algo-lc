class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        m, n = len(matrix), len(matrix[0])
        self.acc = [[0] * n for _ in range(m)]
        for row in range(m):
            row_sum = 0
            for col in range(n):
                upper_rect_sum = 0 if row == 0 else self.acc[row - 1][col]
                row_sum += matrix[row][col]
                self.acc[row][col] = row_sum + upper_rect_sum

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        upper_rect = 0 if row1 == 0 else self.acc[row1 - 1][col2]
        left_rect = 0 if col1 == 0 else self.acc[row2][col1 - 1]
        diag_rect = 0 if col1 == 0 or row1 == 0 else self.acc[row1 - 1][col1 - 1]
        return self.acc[row2][col2] - upper_rect - left_rect + diag_rect

# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)