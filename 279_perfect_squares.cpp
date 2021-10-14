// ///////////////////////////////////////////////////////////////////////////
//
// 279. Perfect Squares
// https://leetcode.com/problems/perfect-squares/
//
// ***************************************************************************
//
//
// Given an integer n, return the least number of perfect square
// numbers that sum to n.
// A perfect square is an integer that is the square of an integer;
// in other words, it is the product of some integer with itself.
// For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
//
//
// Example 1:
// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
//
// Example 2:
// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.
//
// Constraints:
// 1 <= n <= 10^4



#include <cmath>

class Solution {
public:
    int numSquares(int n)
    {
        int table[10'001];
        fill(table, table + 10'000, n + 1);
        table[0] = 0;
        table[1] = 1;
        for (int i = 2; i <= n; i++){
            for (int k = 1; k <= static_cast<int>(sqrt(i)); k++){
                table[i] = min(table[i], 1 + table[i - k * k]);
            }
        }
        return table[n];
    }
};
