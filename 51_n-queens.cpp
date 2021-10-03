// ///////////////////////////////////////////////////////////////////////////
//
// 51. N-Queens
// https://leetcode.com/problems/n-queens/
//
// ***************************************************************************
//
//
// The n-queens puzzle is the problem of placing n queens on an n x n
// chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle.
// Each solution contains a distinct board configuration of the
// n-queens' placement, where 'Q' and '.' both indicate a queen and
// an empty space, respectively.
//
//
// Example 1:
// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
//
//
// Example 2:
// Input: n = 1
// Output: [["Q"]]
//
//
// Constraints:
// 1 <= n <= 9



#include <string>
#include <utility>
#include <vector>

using Pos = std::pair<int, int>;
using namespace std;


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<Pos>> solutions;
        vector<vector<Pos>> newsolutions;
        for (int k = 0; k < n; k++){
            solutions.push_back({Pos(0, k)});
        }
        for (int i = 1; i < n; i++){
            for (const vector<Pos>& path : solutions){
                for (int j = 0; j < n; j++){
                    auto queens = path;
                    queens.push_back(Pos(i, j));
                    if (checkAttacks(queens))
                        newsolutions.push_back(queens);
                }
            }
            solutions.clear();
            solutions.swap(newsolutions);
        }
        string row(n, '.');
        vector<string> board(n, row);
        vector<vector<string>> result;
        for (auto& sol : solutions){
            vector<string> r = board;
            for (auto& Pos : sol){
                r[Pos.first][Pos.second] = 'Q';
            }
            result.push_back(r);
        }
        return result;
    }

    // Checks if a queen attacks some other queen
    // on the board
    bool checkAttacks(vector<Pos> queens){
        for (int i = 0; i < queens.size(); i++){
            for (int j = i + 1; j < queens.size(); j++){
                Pos q0 = queens[i], q1 = queens[j];
                // Check column attack
                if (q0.second == q1.second)
                    return false;
                // Check diagonal attack
                int dx = abs(q0.second - q1.second);
                int dy = abs(q0.first - q1.first);
                if (dx == dy)
                    return false;
            }
        }
        return true;
    }
};
