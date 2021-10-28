// ///////////////////////////////////////////////////////////////////////////
//
// 15. 3Sum
// https://leetcode.com/problems/3sum/
//
// ***************************************************************************
//
//
// Given an integer array nums, return all the triplets [nums[i], nums[j],
// nums[k]] such that i != j, i != k, and j != k, and
// nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.
//
//
// Example 1:
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
//
// Example 2:
// Input: nums = []
// Output: []
//
// Example 3:
// Input: nums = [0]
// Output: []
//
//
// Constraints:
// * 0 <= nums.length <= 3000
// * -10^5 <= nums[i] <= 10^5



#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

    // Slow implementation
    vector<vector<int>> threeSumSlow(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size();){
            for (int j = i + 2; j < nums.size(); j++){
                while (j + 1 < nums.size() && nums[j+1] == nums[j]) j++;
                int sum2 = nums[i] + nums[j];
                int k = binarySearch(nums.begin() + i + 1, nums.begin() + j, -sum2);
                if (k >= 0){
                    result.push_back({nums[i], nums[i + k + 1], nums[j]});
                }
            }
            do {i++;} while (i < nums.size() && nums[i] == nums[i - 1]);
        }
        return result;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size();){
            int k = i + 1;
            int j = nums.size() - 1;
            while (k < j){
                int sum3 = nums[i] + nums[k] + nums[j];
                if (sum3 == 0){
                    result.push_back({nums[i], nums[k], nums[j]});
                    do {k++;} while (k < j && nums[k] == nums[k - 1]);
                    do {j--;} while (k < j && nums[j] == nums[j + 1]);
                }
                else if (sum3 > 0)
                    j--;
                else
                    k++;
            }
            do {i++;} while (i < nums.size() && nums[i] == nums[i-1]);
        }
        return result;
    }

    int binarySearch(
        vector<int>::iterator begin,
        vector<int>::iterator end,
        int target)
    {
        int lo = 0, hi = end - begin;
        while (lo < hi){
            int mid = lo + (hi - lo) / 2;
            int num = *(begin + mid);
            if (num == target)
                return mid;
            else if (num < target)
                lo = mid + 1;
            else
                hi = mid;
        }
        return -1;
    }
};
