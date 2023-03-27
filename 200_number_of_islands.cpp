// ///////////////////////////////////////////////////////////////////////////
//
// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/description/
// 
// ***************************************************************************
//
//
// Given an m x n 2D binary grid grid which represents a map of '1's (land)
// and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent
// lands horizontally or vertically. You may assume all four edges of
// the grid are all surrounded by water.
// 
// 
// Example 1:
// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// 
// 
// Example 2:
// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
// 
// 
// Constraints:
//     * m == grid.length
//     * n == grid[i].length
//     * 1 <= m, n <= 300
//     * grid[i][j] is '0' or '1'.



#include <stack>
#include <vector>
using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited;
        for (int i = 0; i < m; i++)
            visited.push_back(vector<int>(n,0));

        int islands = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1')
                    islands += dfs(i, j, grid, visited);
            }
        }
        return islands;
    }

    int dfs(int row, int col,
            const vector<vector<char>>& grid,
            vector<vector<int>>& visited)
    {
        if (visited[row][col] == 1)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        std::stack<pair<int, int>> S;
        S.push({row, col});

        while (!S.empty()){
            std::pair<int, int> top = S.top();
            S.pop();
            int y = top.first;
            int x = top.second;
            visited[y][x] = 1;
            // top
            if (y - 1 >= 0 && grid[y-1][x] == '1' && visited[y-1][x] == 0)
                S.push({y - 1, x});
            // bottom
            if (y + 1 < m && grid[y+1][x] == '1' && visited[y+1][x] == 0)
                S.push({y + 1, x});
            // left
            if (x - 1 >= 0 && grid[y][x-1] == '1' && visited[y][x-1] == 0)
                S.push({y, x - 1});
            // right
            if (x + 1 < n && grid[y][x+1] == '1' && visited[y][x+1] == 0)
                S.push({y, x + 1});
        }
        return 1;
    }
};
