// ****************************************************************************
// 
// 695. Max Area of Island
// https://leetcode.com/problems/max-area-of-island/
//
// ----------------------------------------------------------------------------
//
//
// You are given an m x n binary matrix grid. An island is a group of 1's
// (representing land) connected 4-directionally (horizontal or vertical.)
// You may assume all four edges of the grid are surrounded by water.
// The area of an island is the number of cells with a value 1 in the island.
// Return the maximum area of an island in grid. If there is no island, return 0.
//
//
// Example 1:
//
// Input: grid = [ [0,0,1,0,0,0,0,1,0,0,0,0,0]
//                 [0,0,0,0,0,0,0,1,1,1,0,0,0],
//                 [0,1,1,0,1,0,0,0,0,0,0,0,0],
//                 [0,1,0,0,1,1,0,0,1,0,1,0,0],
//                 [0,1,0,0,1,1,0,0,1,1,1,0,0],
//                 [0,0,0,0,0,0,0,0,0,0,1,0,0],
//                 [0,0,0,0,0,0,0,1,1,1,0,0,0],
//                 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.
//
//
// Example 2:
//
// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0
// 
// Constraints:
// 
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// grid[i][j] is either 0 or 1



#include <algorithm>
#include <vector>
#include <unordered_set>
#include <utility>

using namespace std;
using point = std::pair<int, int>;


struct PairHash{
    size_t operator()(const point& p) const{
        return p.first ^ p.second;
    } 
};


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        std::unordered_set<point, PairHash> visited{};
        int maxarea = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                point p = std::make_pair(i, j);
                if (grid[i][j] && visited.count(p) == 0){
                    visited.insert(p);
                    maxarea = std::max(maxarea, sweep(grid, i, j, visited));
                }
                   
            }
        }
        return maxarea;
    }

    int sweep(const vector<vector<int>>& grid,
              int i,
              int j,
              std::unordered_set<point, PairHash>& visited)
    {
        int area = 1;
        int m = grid.size();
        int n = grid[0].size();
        if (i - 1 >= 0 && grid[i-1][j]){
            if (visited.insert(std::make_pair(i-1, j)).second)
                area += sweep(grid, i-1, j, visited);
        }
        if (i + 1 < m && grid[i+1][j]){
            if (visited.insert(std::make_pair(i+1, j)).second)
                area += sweep(grid, i+1, j, visited);
        }
        if (j - 1 >= 0 && grid[i][j-1]){
            if (visited.insert(std::make_pair(i, j-1)).second)
                area += sweep(grid, i, j-1, visited);
        }
        if (j + 1 < n && grid[i][j+1]){
            if (visited.insert(std::make_pair(i, j+1)).second)
                area += sweep(grid, i, j+1, visited);
        }
        return area;
    }
};
