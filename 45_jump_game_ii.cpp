// ****************************************************************************
// 
// 45. Jump Game II
// https://leetcode.com/problems/jump-game-ii/
//
// ----------------------------------------------------------------------------
//
//
// Given an array of non-negative integers nums, you are initially
// positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Your goal is to reach the last index in the minimum number of jumps.
// You can assume that you can always reach the last index.
// 
// 
// Example 1:
// 
// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2.
// Jump 1 step from index 0 to 1, then 3 steps to the last index.
// 
// 
// Example 2:
// 
// Input: nums = [2,3,0,1,4]
// Output: 2
// 
// 
// Constraints:
// 
// 1 <= nums.length <= 10^4
// 0 <= nums[i] <= 1000

#include <vector>
using namespace std;

/*
    O(n^2) time, O(1) memory
*/
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         vector<int> steps(nums.size(), 0);
//         for (int i = 0; i < nums.size(); i++){
//             int k = i + nums[i] + 1 < nums.size() ? i + nums[i] + 1 : nums.size();
//             for (int j = i + 1; j < k; j++)
//                 steps[j] = steps[j] == 0 ? 1 + steps[i] : min(steps[j], 1 + steps[i]);
//         }
//         return steps.back();
//     }
// };


/*
    O(n) time, O(k) memory
*/
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         unordered_map<int, int> maxreach{{0, nums[0]}, {1, nums[0]}};
//         int steps_taken = 1;
//         for (int i = 1; i < nums.size(); i++){
//             if (i + nums[i] > maxreach[steps_taken + 1]){
//                 maxreach[steps_taken + 1] = i + nums[i];
//                 if (i + nums[i] >= nums.size() - 1)
//                     return steps_taken + 1;
//             }
//             if (i == maxreach[steps_taken]){
//                 steps_taken++;
//             }
//         }
//         return 0;
//     }
// };


/*
    O(n) time, O(1) memory
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int maxreach_current = 0;
        int maxreach_next = 0;
        int steps_taken = 0;
        for (int i = 0; i < nums.size(); i++){
            if (i + nums[i] > maxreach_next){
                maxreach_next = i + nums[i];
                if (i + nums[i] >= nums.size() - 1)
                    return steps_taken + 1;
            }
            if (i == maxreach_current){
                steps_taken++;
                maxreach_current = maxreach_next;
            }
        }
        return 0;
    }
};
