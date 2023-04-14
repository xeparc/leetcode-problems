// ****************************************************************************
// 
// 516. Longest Palindromic Subsequence
// https://leetcode.com/problems/longest-palindromic-subsequence/description/
//
// ----------------------------------------------------------------------------
//
//
// Given a string s, find the longest palindromic subsequence's length in s.
// A subsequence is a sequence that can be derived from another sequence by
// deleting some or no elements without changing the order of the remaining
// elements.
// 
// Example 1:
// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".
// 
// Example 2:
// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".
// 
// Constraints:
//     * 1 <= s.length <= 1000
//     * s consists only of lowercase English letters.



#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // Find the longest common subsequence
        // between `s` and `s[::-1]`
        //
        // Recursive relations:
        // if a[i] == b[j]
        //      LCS(a[:i], b[:j]) = LCS(a[:i-1], b[:j-1]) + 1
        // else
        //      LCS(a[:i], b[:j]) = max(LCS(a[:i], b[:j-1]), LCS(a[:i-1], b[:j]))
        //
        string r(s.rbegin(), s.rend());
        size_t N = s.size();
        vector<vector<int>> lcs;
        for (int i = 0; i < N; i++)
            lcs.push_back(vector<int>(N, 0));
        
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (s[i] == r[j]){
                    if (i > 0 && j > 0)
                        lcs[i][j] = lcs[i-1][j-1] + 1;
                    else
                        lcs[i][j] = 1;
                }
                else {
                    int top = i > 0 ? lcs[i-1][j] : 0;
                    int left = j > 0 ? lcs[i][j-1] : 0;
                    lcs[i][j] = max(top, left);
                }
            }
        }
        return lcs[N - 1][N - 1];
    }
};
