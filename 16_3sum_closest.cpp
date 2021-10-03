// ****************************************************************************
// 
// 16. 3Sum Closest
// https://leetcode.com/problems/3sum-closest/
// 
// ----------------------------------------------------------------------------
//
//
// Given an array nums of n integers and an integer target, find three
// integers in nums such that the sum is closest to target.
// Return the sum of the three integers. You may assume that each
// input would have exactly one solution.
//
//
// Example 1:
//
// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
//
// Constraints:
//
// 3 <= nums.length <= 10^3
// -10^3 <= nums[i] <= 10^3
// -10^4 <= target <= 10^4



#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++){
            int res = nums[i] + twoSumClosest(nums.begin() + i + 1, nums.end(), target - nums[i]);
            if (abs(target - res) < abs(target - result))
                result = res;
        }
        return result;
    }
    
    int twoSumClosest(vector<int>::iterator start, vector<int>::iterator end, int target) {
        end--;
        int result = *start + *end;
        while (start < end){
            int current = *start + *end;
            if (abs(target - current) < abs(target - result))
                result = current;
            if (*start + *end < target) start++;
            else if (*start + *end > target) end--;
            else break;
        }
        return result;
    }
};
