// ///////////////////////////////////////////////////////////////////////////
//
// 34. Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
//
// ***************************************************************************
//
//
// Given an array of integers nums sorted in ascending order, find
// the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.
//
//
// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
//
// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
//
// Example 3:
// Input: nums = [], target = 0
// Output: [-1,-1]
//
// Constraints:
// 0 <= nums.length <= 10^5
// -10^9 <= nums[i] <= 10^9
// nums is a non-decreasing array.
// -10^9 <= target <= 10^9



#include <vector>
using namespace std;


class Solution {
public:
    // vector<int> searchRange(vector<int>& nums, int target) {
    //     int mid = binarySearch(nums, target);
    //     if (mid < 0)
    //         return {-1, -1};
    //     else {
    //         // Find first position
    //         int left_lo = 0, left_hi = mid;
    //         while (left_lo < left_hi){
    //             int m = left_lo + (left_hi - left_lo) / 2;
    //             if (nums[m] < target)
    //                 left_lo = m + 1;
    //             else // nums[m] == target
    //                 left_hi = m - 1;
    //         }
    //         // Find last position
    //         int right_lo = mid, right_hi = nums.size();
    //         while (right_lo < right_hi){
    //             int m = right_lo + (right_hi - right_lo) / 2;
    //             if (nums[m] > target)
    //                 right_hi = m - 1;
    //             else // nums[m] == target
    //                 right_lo = m + 1;
    //         }
    //         if (right_hi == nums.size() || nums[right_hi] > target)
    //             right_hi--;
    //         if (nums[left_lo] < target)
    //             left_lo++;
    //         return {left_lo, right_hi};
    //     }
    // }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {lowerBound(nums, target), upperBound(nums, target)};
    }

    int binarySearch(vector<int> nums, int target){
        int lo = 0, hi = nums.size();
        while (lo < hi){
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid;
        }
        return -1;
    }

    int lowerBound(vector<int> nums, int target)
    {
        int lo = 0, hi = nums.size();
        while (lo < hi){
            int m = lo + (hi - lo) / 2;
            if (nums[m] < target)
                lo = m + 1;
            else
                hi = m;
        }
        if (lo < nums.size() && nums[lo] == target)
            return lo;
        return -1;
    }

    int upperBound(vector<int> nums, int target)
    {
        int lo = 0, hi = nums.size();
        while (lo < hi){
            int m = lo + (hi - lo) / 2;
            if (nums[m] > target)
                hi = m;
            else
                lo = m + 1;
        }
        if (lo > 0 && nums[lo - 1] == target)
            return lo - 1;
        return -1;
    }
};
