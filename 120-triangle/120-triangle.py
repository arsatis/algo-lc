class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        # top-down
#         def dfs(i, j):
#             if i == len(triangle) - 1: return triangle[i][j]
#             if memo[i][j] == None:
#                 memo[i][j] = triangle[i][j] + min(dfs(i + 1, j), dfs(i + 1, j + 1))
#             return memo[i][j]
#         memo = [[None] * len(triangle) for _ in range(len(triangle))]
#         return dfs(0, 0)

        # bottom-up, recursive
#         def fill_all(i):
#             if i == -1: return
#             for j in range(i + 1):
#                 triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1])
#             fill_all(i - 1)
#         fill_all(len(triangle) - 2)
#         return triangle[0][0]
    
        # bottom-up, iterative
        for i in range(len(triangle) - 2, -1, -1):
            for j in range(i + 1):
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1])
        return triangle[0][0]