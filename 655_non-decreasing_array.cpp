// ///////////////////////////////////////////////////////////////////////////
//
// 655. Non-decreasing Array
// https://leetcode.com/problems/non-decreasing-array/
//
// ***************************************************************************
//
//
// Given an array nums with n integers, your task is to check if it could
// become non-decreasing by modifying at most one element.
// We define an array is non-decreasing if nums[i] <= nums[i + 1]
// holds for every i (0-based) such that (0 <= i <= n - 2).
//
//
// Example 1:
// Input: nums = [4,2,3]
// Output: true
// Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
//
// Example 2:
// Input: nums = [4,2,1]
// Output: false
// Explanation: You can't get a non-decreasing array by modify at most one element.
//
// Constraints:
// n == nums.length
// 1 <= n <= 10^4
// -10^5 <= nums[i] <= 10^5



#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        // Find the longest continuous left subarray
        for (; i + 1 < nums.size() && nums[i] <= nums[i + 1]; i++);
        if (i == nums.size() - 1)
            return true;
        // Fing the longest continuous right subarray
        for (; j > 0 && nums[j - 1] <= nums[j]; j--);
        if (j - i >= 2)
            return false;
        // We want
        //      nums[i] <= nums[i + 1] <= nums[j]
        // for all `i` and `j`
        //
        // Violations of the above condition:
        //     1. nums[i] <= nums[i + 1] > nums[j]
        //     2. nums[i] > nums[i + 1] <= nums[j]
        //     3. nums[i] > nums[i + 1] > nums[j]
        //
        // We can always modify the first and last elements
        if (i == 0 || j == nums.size() - 1)
            return true;
        // Check if we can achieve monotonicity by modifying i or j
        if (j - i == 1)
            return (nums[i - 1] <= nums[j]) || (nums[i] <= nums[j + 1]);
        // Default
        return false;
    }

    bool checkPossibilityFast(vector<int>& nums) {
        int i = 0;
        int p = -1;
        // Find the inversion if any exist
        for (; i < nums.size() - 1; i++){
            if (nums[i] > nums[i + 1]){
                if (p >= 0) return false;
                p = i;
            }
        }
        if (p < 0) return true;
        if (p == 0 || p == nums.size() - 2)
            return true;
        if (nums[p - 1] <= nums[p + 1] || nums[p] <= nums[p + 2])
            return true;
        return false;
    }
};
