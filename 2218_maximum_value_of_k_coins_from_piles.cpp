// ****************************************************************************
// 
// 2218. Maximum Value of K Coins From Piles
// https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/description/
//
// ----------------------------------------------------------------------------
//
//
// There are n piles of coins on a table. Each pile consists of a positive
// number of coins of assorted denominations. In one move, you can choose any
// coin on top of any pile, remove it, and add it to your wallet.
// Given a list piles, where piles[i] is a list of integers denoting the
// composition of the ith pile from top to bottom, and a positive integer k,
// return the maximum total value of coins you can have in your wallet if
// you choose exactly k coins optimally.
// 
// Example 1:
// Input: piles = [[1,100,3],[7,8,9]], k = 2
// Output: 101
// Explanation:
// The above diagram shows the different ways we can choose k coins.
// The maximum total we can obtain is 101.
// 
// Example 2:
// Input: piles = [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]], k = 7
// Output: 706
// Explanation:
// The maximum total can be obtained if we choose all coins from the last pile.
// 
// Constraints:
//     * n == piles.length
//     * 1 <= n <= 1000
//     * 1 <= piles[i][j] <= 10^5
//     * 1 <= k <= sum(piles[i].length) <= 2000



#include <numeric>
#include <vector>
using namespace std;


class Solution {
public:
int maxValueOfCoins(vector<vector<int>>& piles, int k){
        constexpr int NA = -1;

        // Initialize memo table.
        // table[p][C] is the maximum value we can
        // obtain from piles 1...p with C coins 
        vector<vector<int>> table;
        for (int i = 0; i < piles.size(); i++)
            table.push_back(vector<int>(k+1, NA));

        // Calculate prefix sums
        for (vector<int>& pile : piles){
            partial_sum(pile.begin(), pile.end(), pile.begin());
        }

        for (int p = 0; p < piles.size(); p++){
            const vector<int>& pile = piles[p];
            table[p][0] = 0;
            // Special case: first pile of coins
            if (p == 0){
                for (int i = 0; i < min(k, static_cast<int>(pile.size())); i++){
                    table[p][i+1] = pile[i];
                }
                continue;
            } else {
                for (int j = 1; j <= k; j++){
                    int maxvalue = NA;
                    for (int i = 0; i <= j; i++){
                        if (i > pile.size())
                            break;
                        // Maximum value of coins we can collect
                        // from all piles left to current pile
                        int left_coins = (table[p-1][j-i] == NA) ? NA : table[p-1][j-i];
                        // Value of coins from this pile
                        int this_coins = NA;
                        if (i == 0)
                            this_coins = 0;
                        else if (i - 1 < pile.size())
                            this_coins = pile[i-1];
                        int isNA = (left_coins == NA) || (this_coins == NA);
                        int total = isNA ? NA : left_coins + this_coins;
                        maxvalue = max(total, maxvalue);
                    }
                    table[p][j] = maxvalue;
                }
            }
        }
        // for (int j = 0; j <= k; j++){
        //     for (int i = 0; i < piles.size(); i++){
        //         cout << table[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        return table[piles.size() - 1][k];
    }

    int maxValueOfCoinsEditorial(vector<vector<int>>& piles, int k) {
        constexpr int NA = 0;

        // Initialize memo table.
        // table[p][C] is the maximum value we can
        // obtain from piles 1...p with C + 1 coins.
        vector<vector<int>> table (piles.size() + 1, vector<int>(k + 1, NA));

        for (int p = 1; p <= piles.size(); p++){
            const vector<int>& pile = piles[p-1];
            for (int coins = 0; coins <= k ; coins++){
                // Value of coins from this pile
                int coins_sum = 0;
                for (int i = 0; i <= coins; i++){
                    if (i - 1 == pile.size())
                        break;
                    if (i > 0)
                        coins_sum += pile[i - 1];
                    table[p][coins] = max(table[p][coins], table[p-1][coins - i] + coins_sum);
                }
            }
        }
        return table[piles.size()][k];
    }

};
