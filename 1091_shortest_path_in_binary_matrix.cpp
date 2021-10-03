//////////////////////////////////////////////////////////////////////////////
//
// 1091. Shortest Path in Binary Matrix
// https://leetcode.com/problems/shortest-path-in-binary-matrix/
//
// ***************************************************************************


// In an N by N square grid, each cell is either empty (0) or blocked (1).

// A clear path from top-left to bottom-right has length k if and only if it
// is composed of cells C_1, C_2, ..., C_k such that:

// * Adjacent cells C_i and C_{i+1} are connected 8-directionally
//   (ie., they are different and share an edge or corner)
// * C_1 is at location (0, 0) (ie. has value grid[0][0])
// * C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
// * If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).

// Return the length of the shortest such clear path from top-left to
// bottom-right.  If such a path does not exist, return -1.


// Note:
//     1 <= grid.length == grid[0].length <= 100
//     grid[r][c] is 0 or 1


#include <array>
#include <vector>

using namespace std;
using coord = std::pair<int, int>;
using node = std::pair<coord, int>;


class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0])
            return -1;
        size_t N = grid.size();
        std::vector<node> frontier {{{0, 0}, 1}};
        char visited[100][100] = {0,};
        visited[0][0] = 1;
        std::array<node, 8> neighbours;
        while (!frontier.empty()){
            std::pop_heap(frontier.begin(),
                          frontier.end(),
                          [](const node a, const node b){return a.second > b.second;});
            const auto [point, length] = frontier.back();
            const auto [x, y] = point;
            frontier.pop_back();
            // Check if the node is the (N-1, N-1) cell
            if (x == N - 1 && y == N - 1)
                return length;

            int n = 0;
            // Check each 8-way direction for 0 cell
            // -------------------------------------
            // Right
            if (x + 1 < N && !visited[y][x + 1] && grid[y][x + 1] == 0){
                visited[y][x + 1] = 1;
                neighbours[n++] = {{x + 1, y}, length + 1};
            }
            // Down
            if (y + 1 < N && !visited[y + 1][x] && grid[y + 1][x] == 0){
                visited[y + 1][x] = 1;
                neighbours[n++] = {{x, y + 1}, length + 1};
            }
            // Down-Right
            if (x + 1 < N && y + 1 < N && !visited[y + 1][x + 1] && !grid[y + 1][x + 1]){
                visited[y + 1][x + 1] = 1;
                neighbours[n++] = {{x + 1, y + 1}, length + 1};
            }
            // Up
            if (y - 1 >= 0 && !visited[y - 1][x] && grid[y - 1][x] == 0){
                visited[y - 1][x] = 1;
                neighbours[n++] = {{x, y - 1}, length + 1};
            }
            // Up-Right
            if (y - 1 >= 0 && x + 1 < N && !visited[y - 1][x + 1] && !grid[y - 1][x + 1]){
                visited[y - 1][x + 1] = 1;
                neighbours[n++] = {{x + 1, y - 1}, length + 1};
            }
            // Left
            if (x - 1 >= 0 && !visited[y][x - 1] && grid[y][x - 1] == 0){
                visited[y][x - 1] = 1;
                neighbours[n++] = {{x - 1, y}, length + 1};
            }
            // Left-Up
            if (x - 1 >= 0 && y - 1 >= 0 && !visited[y - 1][x - 1] && !grid[y - 1][x - 1]){
                visited[y - 1][x - 1] = 1;
                neighbours[n++] = {{x - 1, y - 1}, length + 1};
            }
            // Left-Down
            if ((x - 1 >= 0) && (y + 1 < N) && !visited[y + 1][x - 1] && !grid[y + 1][x - 1]){
                visited[y + 1][x - 1] = 1;
                neighbours[n++] = {{x - 1, y + 1}, length + 1};
            }
            // Add neighbours to frontier
            while (n-- > 0){
                frontier.push_back(neighbours[n]);
                std::push_heap(frontier.begin(),
                               frontier.end(),
                               [](const node a, const node b){return a.second > b.second;});
            }
        }
        return -1;
    }
};
