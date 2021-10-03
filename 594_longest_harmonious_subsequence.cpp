// ****************************************************************************
// 
// 594. Longest Harmonious Subsequence
// https://leetcode.com/problems/longest-harmonious-subsequence/
//
// ----------------------------------------------------------------------------


// We define a harmounious array as an array where the difference between
// its maximum value and its minimum value is exactly 1.
// Now, given an integer array, you need to find the length of its longest
// harmonious subsequence among all its possible subsequences.

// Example 1:
// Input: [1,3,2,2,5,2,3,7]
// Output: 5
// Explanation: The longest harmonious subsequence is [3,2,2,2,3].
 

// Note: The length of the input array will not exceed 20,000.

#include <unordered_map>

class Solution {
public:
    int findLHS(vector<int>& nums) {
        std::unordered_map<int, int> counter;
        for (int n : nums)
            counter[n]++;
        int longest = 0;
        for (auto p : counter){
            auto q = counter.find(p.first + 1);
            if (q != counter.end()){
                int len = p.second + q->second;
                longest = len > longest ? len : longest;
            }
        }
        return longest;
    }
};