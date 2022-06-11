//////////////////////////////////////////////////////////////////////////////
//
// 1658. Minimum Operations to Reduce X to Zero
// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
//
// ***************************************************************************
// // 
// // 
// You are given an integer array nums and an integer x. In one operation,
// you can either remove the leftmost or the rightmost element from the
// array nums and subtract its value from x. Note that this modifies the
// array for future operations.
// Return the minimum number of operations to reduce x to exactly 0 if it
// is possible, otherwise, return -1.
// 
// 
// Example 1:
// Input: nums = [1,1,4,2,3], x = 5
// Output: 2
// Explanation: The optimal solution is to remove the last two elements to
// reduce x to zero.
// 
// Example 2:
// Input: nums = [5,6,7,8,9], x = 4
// Output: -1
// 
// Example 3:
// Input: nums = [3,2,20,1,1,3], x = 10
// Output: 5
// Explanation: The optimal solution is to remove the last three elements and
// the first two elements (5 operations in total) to reduce x to zero.
// 
// Constraints:
// 1 <= nums.length <= 10^5
// 1 <= nums[i] <= 10^4
// 1 <= x <= 10^9



#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if (nums.back() == x || nums.front() == x)
            return 1;
        std::vector<int> suffix_sum(nums.size());
        std::partial_sum(nums.rbegin(), nums.rend(), suffix_sum.rbegin());
        if (suffix_sum.front() < x)
            return -1;
        std::vector<int>::reverse_iterator R = std::lower_bound(
            suffix_sum.rbegin(),
            suffix_sum.rend(),
            x
        );
        int minops = INT_MAX;
        if (R < suffix_sum.rend() && *R == x)
            minops = 1 + std::min(minops, static_cast<int>(R - suffix_sum.rbegin()));
        int accum = 0;
        for (int i = 0; i < nums.size() && accum <= x; i++){
            accum += nums[i];
            int y = x - accum;
            if (y == 0){
                minops = std::min(minops, 1 + i);
                break;
            }
            auto it2 = std::lower_bound(
                suffix_sum.rbegin(),
                R,
                y);
            if (it2 < R && *it2 == y){
                int j = std::distance(suffix_sum.rbegin(), it2);
                minops = std::min(minops, 2 + i + j);
            }
        }
        return minops == INT_MAX ? -1 : minops;
    }

    int minOperationsFast(vector<int>& nums, int x) {
        int i = 0, sum = 0, maxlen = -1;
        int y = std::accumulate(nums.begin(), nums.end(), 0) - x;
        if (y == 0)
            return nums.size();
        for (int j = 1; j < nums.size() + 1; j++){
            sum += nums[j-1];
            while (sum > y && i < j)
                sum -= nums[i++];
            if (sum == y && i < j)
                maxlen = std::max(maxlen, j - i);
        }
        return maxlen == -1 ? -1 : nums.size() - maxlen;
    }
};

//         v
// 1,  2,  6, 8, 11
// 11, 10, 9, 5, 3
//            ^

//         v
//  3, 5,  25, 26, 27, 30
// 30, 27, 25,  5,  4, 3
//          ^