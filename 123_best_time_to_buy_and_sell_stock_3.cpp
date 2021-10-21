// ///////////////////////////////////////////////////////////////////////////
//
// 123. Best Time to Buy and Sell Stock III
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
//
// ***************************************************************************
//
//
// You are given an array prices where prices[i] is the price of a given
// stock on the ith day. Find the maximum profit you can achieve.
// You may complete at most two transactions.
// Note: You may not engage in multiple transactions simultaneously
// (i.e., you must sell the stock before you buy again).
//
//
// Example 1:
// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
//
// Example 2:
// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Note that you cannot buy on day 1, buy on day 2 and sell them later,
// as you are engaging multiple transactions at the same time.
// You must sell before buying again.
//
// Example 3:
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.
//
// Example 4:
// Input: prices = [1]
// Output: 0
//
//
// Constraints:
// * 1 <= prices.length <= 10^5
// * 0 <= prices[i] <= 10^5



#include <vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        vector<int> best_left(prices.size() - 1);
        int best = INT_MIN;
        int current = 0;
        for (int i = 0; i < prices.size() - 1; i++){
            int delta = prices[i + 1] - prices[i];
            current = max(delta, current + delta);
            if (current < 0)
                current = delta;
            best = max(best, current);
            best_left[i] = best;
        }
        vector<int> best_right(prices.size() - 1);
        best = INT_MIN;
        current = 0;
        int best_2 = INT_MIN;
        for (int j = prices.size() - 1; j > 0; j--){
            int delta = prices[j] - prices[j - 1];
            current = max(delta, current + delta);
            if (current < 0)
                current = delta;
            best = max(best, current);
            best_right[j - 1] = best;
            if (j - 2 >= 0)
                best_2 = max(best_2, best_left[j-2] + best_right[j-1]);
        }
        int best_overall = max(best_2, best_left.back());
        return max(0, best_overall);
    }
};
