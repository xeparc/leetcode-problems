// ///////////////////////////////////////////////////////////////////////////
//
// 1254. Number of Closed Islands
// https://leetcode.com/problems/number-of-closed-islands/description/
// ***************************************************************************
//
//
// Given a 2D grid consists of 0s (land) and 1s (water).
// An island is a maximal 4-directionally connected group of 0s and a
// closed island is an island totally (all left, top, right, bottom)
// surrounded by 1s.
// Return the number of closed islands.
// 
// 
// Example 1:
// Input: grid = [[1,1,1,1,1,1,1,0],
//                [1,0,0,0,0,1,1,0],
//                [1,0,1,0,1,1,1,0],
//                [1,0,0,0,0,1,0,1],
//                [1,1,1,1,1,1,1,0]]
// Output: 2
// Explanation: 
// Islands in gray are closed because they are completely surrounded
// by water (group of 1s).
// 
// Example 2:
// Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
// Output: 1
// 
// Example 3:
// Input: grid = [[1,1,1,1,1,1,1],
//                [1,0,0,0,0,0,1],
//                [1,0,1,1,1,0,1],
//                [1,0,1,0,1,0,1],
//                [1,0,1,1,1,0,1],
//                [1,0,0,0,0,0,1],
//                [1,1,1,1,1,1,1]]
// Output: 2
// 
// Constraints:
//     * 1 <= grid.length, grid[0].length <= 100
//     * 0 <= grid[i][j] <= 1



#include <stack>
#include <vector>
using namespace std;


class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited;
        for (int i = 0; i < m; i++)
            visited.push_back(vector<int>(n, 0));

        constexpr int Black = 2;
        constexpr int White = 0;

        int islands = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1 || visited[i][j] == Black)
                    continue;

                stack<pair<int, int>> S;
                S.push(make_pair(i, j));
                bool isolated = true;

                while (!S.empty()){
                    int y = S.top().first;
                    int x = S.top().second;
                    S.pop();

                    if (visited[y][x] == Black)
                        continue;

                    visited[y][x] = Black;
                    if (y - 1 >= 0 && grid[y - 1][x] == 0 && visited[y - 1][x] == White)
                        S.push(make_pair(y - 1, x));
                    if (y + 1 < m && grid[y + 1][x] == 0 && visited[y + 1][x] == White)
                        S.push(make_pair(y + 1, x));
                    if (x - 1 >= 0 && grid[y][x - 1] == 0 && visited[y][x - 1] == White)
                        S.push(make_pair(y, x - 1));
                    if (x + 1 < n && grid[y][x + 1] == 0 && visited[y][x + 1] == White)
                        S.push(make_pair(y, x + 1));

                    if (y - 1 < 0 || y + 1 >= m || x - 1 < 0 || x + 1 >= n)
                        isolated = false;
                }
                islands += isolated;
            }
        }
        return islands;
    }
};
