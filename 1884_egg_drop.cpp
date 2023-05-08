// ****************************************************************************
// 
// 1884. Egg Drop With 2 Eggs and N Floors
// https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/description/
//
// ----------------------------------------------------------------------------
//
//
// You are given two identical eggs and you have access to a building with
// n floors labeled from 1 to n. You know that there exists a floor f where
// 0 <= f <= n such that any egg dropped at a floor higher than f will break,
// and any egg dropped at or below floor f will not break.
// In each move, you may take an unbroken egg and drop it from any floor x
// (where 1 <= x <= n). If the egg breaks, you can no longer use it.
// However, if the egg does not break, you may reuse it in future moves.
// Return the minimum number of moves that you need to determine with
// certainty what the value of f is.
// 
// 
// Example 1:
// 
// Input: n = 2
// Output: 2
// Explanation: We can drop the first egg from floor 1 and the second egg from floor 2.
// If the first egg breaks, we know that f = 0.
// If the second egg breaks but the first egg didn't, we know that f = 1.
// Otherwise, if both eggs survive, we know that f = 2.
// 
// 
// Example 2:
// 
// Input: n = 100
// Output: 14
// Explanation: One optimal strategy is:
// - Drop the 1st egg at floor 9. If it breaks, we know f is between 0 and 8.
//   Drop the 2nd egg starting from floor 1 and going up one at a time to find
//   if within 8 more drops. Total drops is 1 + 8 = 9.
// - If the 1st egg does not break, drop the 1st egg again at floor 22.
//   If it breaks, we know f is between 9 and 21. Drop the 2nd egg starting
//   from floor 10 and going up one at a time to find f within 12 more drops.
//   Total drops is 2 + 12 = 14.
// - If the 1st egg does not break again, follow a similar process dropping
//   the 1st egg from floors 34, 45, 55, 64, 72, 79, 85, 90, 94, 97, 99, and 100.
// Regardless of the outcome, it takes at most 14 drops to determine f.
//  
// 
// Constraints:
// 
//     * 1 <= n <= 1000



#include <vector>
#include <numeric>

using namespace std;


class Solution {
public:
    int twoEggDrop(int n) {
        vector<vector<int>> table(2, vector<int>(n+1, 0));
        std::iota(table[0].begin(), table[0].end(), 0);
        table[1][0] = 0;
        table[1][1] = 1;

        for (int i = 2; i < n+1; i++){
            int drops = i;
            for (int j = 1; j <= i; j++){
                int ifbreaks = 1 + table[0][j - 1];
                int ifnotbreaks = 1 + table[1][i - j];
                drops = min(drops, max(ifbreaks, ifnotbreaks));
            }
            table[1][i] = drops;
        }
        return table[1][n];
    }
};
