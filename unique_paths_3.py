class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        M, N = range(len(grid)), range(len(grid[0]))
        tovisit = frozenset((i, j) for i in M for j in N if grid[i][j] == 0 or grid[i][j] == 1)

        def backtrack(current, visited):
            i, j = current
            if not (0 <= i < len(grid)) or not (0 <= j < len(grid[0])):
                return 0
            cell = grid[i][j]
            if current in visited or cell == -1:
                return 0
            if cell == 2:
                return 1 if visited == tovisit else 0
            
            V = visited | frozenset([current])
            left = backtrack((i, j - 1), V)
            right = backtrack((i, j + 1), V)
            up = backtrack((i - 1, j), V)
            down = backtrack((i + 1, j), V)
            return left + right + up + down
            
        # Find the index of the starting square
        M, N = range(len(grid)), range(len(grid[0]))
        s = [(i, j) for i in M for j in N if grid[i][j] == 1]
        if not s:
            return 0
        visited = frozenset()
        return backtrack(s[0], visited)
        
 
