// ///////////////////////////////////////////////////////////////////////////
//
// 976. Largest Perimeter Triangle
// https://leetcode.com/problems/largest-perimeter-triangle/description/
//
// ***************************************************************************
//
//
// Given an integer array nums, return the largest perimeter of a triangle
// with a non-zero area, formed from three of these lengths.
// If it is impossible to form any triangle of a non-zero area, return 0.
// 
// 
// Example 1:
// Input: nums = [2,1,2]
// Output: 5
// 
// Example 2:
// Input: nums = [1,2,1]
// Output: 0
// 
// Constraints:
//   * 3 <= nums.length <= 10^4
//   * 1 <= nums[i] <= 10^6



#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int k = n - 1; k >= 2; k--){
            int j = k - 1;
            int i = k - 2;
            if (nums[k] < nums[i] + nums[j])
                return nums[i] + nums[j] + nums[k];
        }
        return 0;
    }
};
