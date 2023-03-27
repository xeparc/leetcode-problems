// ///////////////////////////////////////////////////////////////////////////
//
// 64. Minimum Path Sum
// https://leetcode.com/problems/minimum-path-sum/description/
// 
// ***************************************************************************
//
//
// Given a m x n grid filled with non-negative numbers, find a path from top
// left to bottom right, which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.
// 
// Example 1:
// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
// 
// Example 2:
// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12
// 
// Constraints:
//     * m == grid.length
//     * n == grid[i].length
//     * 1 <= m, n <= 200
//     * 0 <= grid[i][j] <= 100



#include <vector>
#include <limits>

using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        vector<vector<int>> paths;
        for (int j = 0; j < m; j++)
            paths.push_back(vector<int>(n, 0));
        paths[0] = grid[0];

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (i == 0 && j == 0)
                    continue;
                long long top  = i - 1 >= 0 ? paths[i-1][j] : numeric_limits<int>::max();
                long long left = j - 1 >= 0 ? paths[i][j-1] : numeric_limits<int>::max();
                paths[i][j] = static_cast<int>(min(top + grid[i][j], left + grid[i][j])); 
            }
        }
        return paths[m-1][n-1];
    }
};
