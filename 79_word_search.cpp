// ///////////////////////////////////////////////////////////////////////////
//
// 79. Word Search
// https://leetcode.com/problems/word-search/
//
// ***************************************************************************
//
//
// Given an m x n grid of characters board and a string word,
// return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells,
// where adjacent cells are horizontally or vertically neighboring.
// The same letter cell may not be used more than once.
//
//
// Example 1:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
//
// Example 2:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
//
// Example 3:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false
//
//
// Constraints:
//
// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.
//
//
// Follow up: Could you use search pruning to make your solution faster with a larger board?



#include <algorithm>
#include <deque>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using pos = pair<int, int>;


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        deque<pos> visited(64);
        visited.clear();
        // int visited[6][6] = {0,};
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); j++){
                visited.push_back({i,j});
                if (dfs(board, visited, word, 0))
                    return true;
                visited.clear();
                // visited[i][j] = 1;
                // if (dfs2(board, visited, {i,j}, word, 0))
                //     return true;
                // memset(visited, 0, 36 * sizeof(int));
            }
        }
        return false;
    }

    bool dfs2(
        const vector<vector<char>>& board,
        int visited[][6],
        pos start,
        const string& word,
        size_t k)
    {
        int i = start.first;
        int j = start.second;
        if (word[k] != board[i][j])
            return false;
        if (k + 1 == word.size())
            return true;
        bool result = false;
        // top neighbour
        if (i - 1 >= 0 && !visited[i-1][j] && word[k+1] == board[i-1][j]){
            visited[i-1][j] = 1;
            if (dfs2(board, visited, {i-1,j}, word, k+1))
                return true;
            visited[i-1][j] = 0;
        }
        // bottom neighbour
        if (i + 1 < board.size() && !visited[i+1][j] && word[k+1] == board[i+1][j]){
            visited[i+1][j] = 1;
            if (dfs2(board, visited, {i+1,j}, word, k+1))
                return true;
            visited[i+1][j] = 0;
        }
        // left neighbour
        if (j-1 >= 0 && !visited[i][j-1] && word[k+1] == board[i][j-1]){
            visited[i][j-1] = 1;
            if (dfs2(board, visited, {i,j-1}, word, k+1))
                return true;
            visited[i][j-1] = 0;
        }
        // right neighbour
        if (j+1 < board[i].size() && !visited[i][j+1] && word[k+1] == board[i][j+1]){
            visited[i][j+1] = 1;
            if (dfs2(board, visited, {i,j+1}, word, k+1))
                return true;
            visited[i][j+1] = 0;
        }
        return false;
    }


    // Very slow
    bool dfs(
        const vector<vector<char>>& board,
        deque<pos>& visited,
        const string& word,
        size_t k)
    {
        int i = visited.back().first;
        int j = visited.back().second;
        pos P {i, j};
        if (visited.size() > 1 && find(visited.begin(), visited.end() - 1, P) != visited.end() - 1)
            return false;
        if (board[i][j] != word[k])
            return false;
        if (++k == word.size())
            return true;

        // top neighbour
        if (i-1 >= 0 && word[k] == board[i-1][j]) {
            visited.push_back({i-1, j});
            if (dfs(board, visited, word, k))
                return true;
            visited.pop_back();
        }
        // bottom neighbour
        if (i + 1 < board.size() && word[k] == board[i+1][j]) {
            visited.push_back({i + 1, j});
            if (dfs(board, visited, word, k))
                return true;
            visited.pop_back();
        }
        // left neighbour
        if (j - 1 >= 0 && word[k] == board[i][j-1]) {
            visited.push_back({i, j-1});
            if (dfs(board, visited, word, k))
                return true;
            visited.pop_back();
        }
        // right neighbour
        if (j + 1 < board[i].size() && word[k] == board[i][j+1]) {
            visited.push_back({i, j+1});
            if (dfs(board, visited, word, k))
                return true;
            visited.pop_back();
        }
        return false;
    }
};
