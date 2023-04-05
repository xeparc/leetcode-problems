// ****************************************************************************
// 
// 2439. Minimize Maximum of Array
// https://leetcode.com/problems/minimize-maximum-of-array/description/
//
// ----------------------------------------------------------------------------
//
//
// You are given a 0-indexed array nums comprising of n non-negative integers.
// In one operation, you must: 
//     Choose an integer i such that 1 <= i < n and nums[i] > 0.
//     Decrease nums[i] by 1.
//     Increase nums[i - 1] by 1.
// Return the minimum possible value of the maximum integer of nums after
// performing any number of operations.
// 
// Example 1:
// Input: nums = [3,7,1,6]
// Output: 5
// Explanation:
// One set of optimal operations is as follows:
// 1. Choose i = 1, and nums becomes [4,6,1,6].
// 2. Choose i = 3, and nums becomes [4,6,2,5].
// 3. Choose i = 1, and nums becomes [5,5,2,5].
// The maximum integer of nums is 5. It can be shown that the maximum
// number cannot be less than 5.
// Therefore, we return 5.
// 
// Example 2:
// Input: nums = [10,1]
// Output: 10
// Explanation:
// It is optimal to leave nums as is, and since 10 is the maximum value,
// we return 10.
// 
// Constraints:
//     * n == nums.length
//     * 2 <= n <= 10^5
//     * 0 <= nums[i] <= 10^9



#include <vector>
using namespace std;


class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long capacity = 0;
        int max = nums[0];
        int len = 1;
        // Loop Invariant:
        //
        //  *   At the start of each iteration all elements
        //      in nums[0:i] are in nonincreaseing order,
        //      capacity >= 0 and `max` is the maximum value
        //      in nums[0:i]
        for (int i = 1; i < nums.size(); i++, len++){
            if (nums[i] < max){
                capacity += max - nums[i];
            } else if (nums[i] > max) {
                long long diff = static_cast<long long>(nums[i]) - max; 
                long long spill = min(capacity, diff);
                capacity -= spill;
                diff -= spill;
                if (diff > 0){
                    int h = diff / (len + 1);
                    int r = diff % (len + 1);
                    max += (r == 0) ? h : h + 1;
                    capacity = (r == 0) ? 0 : (len + 1) - r;
                }
            }
        }
        return max;
    }
};
