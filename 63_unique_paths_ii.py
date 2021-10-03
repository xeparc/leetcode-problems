class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if not obstacleGrid:
            return 0
        M, N = len(obstacleGrid) + 1, len(obstacleGrid[0]) + 1
        grid = [[0] * N for _ in range(M)]
        grid[-1][-2] = grid[-2][-1] = 0.5
        for i in range(M - 2, -1, -1):
            for j in range(N - 2, -1, -1):
                if obstacleGrid[i][j] == 0:
                    grid[i][j] = grid[i + 1][j] + grid[i][j + 1]
                else:
                    grid[i][j] = 0
        return int(grid[0][0])


