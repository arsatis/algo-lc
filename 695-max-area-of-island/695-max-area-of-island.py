class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        def bfs(i_orig, j_orig) -> int:
            if not grid[i_orig][j_orig]: return 0
            q = deque([(i_orig, j_orig)])
            size = 0
            while q:
                i, j = q.popleft()
                if not visited[i][j]:
                    if i - 1 >= 0 and grid[i - 1][j]: q.append((i - 1, j))
                    if i + 1 < len(grid) and grid[i + 1][j]: q.append((i + 1, j))
                    if j - 1 >= 0 and grid[i][j - 1]: q.append((i, j - 1))
                    if j + 1 < len(grid[0]) and grid[i][j + 1]: q.append((i, j + 1))
                    size += 1
                visited[i][j] = 1
            return size
        
        visited = [[0] * len(grid[0]) for _ in range(len(grid))]
        max_size = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if visited[i][j]: continue
                size = bfs(i, j)
                max_size = max(max_size, size)
        return max_size