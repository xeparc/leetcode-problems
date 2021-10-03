//////////////////////////////////////////////////////////////////////////////
//
// 462. Minimum Moves to Equal Array Elements II
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
//
// ***************************************************************************

// Given a non-empty integer array, find the minimum number of moves
// required to make all array elements equal, where a move is
// incrementing a selected element by 1 or decrementing a selected element by 1.

// You may assume the array's length is at most 10,000.

// Example:

// Input:
// [1,2,3]

// Output:
// 2

// Explanation:
// Only two moves are needed (remember each move increments or
// decrements one element):

// [1,2,3]  =>  [2,2,3]  =>  [2,2,2]



#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        if (nums.size() % 2){
            int m = nums[nums.size() / 2];
            return calculateMoves(nums, m);
        } else {
            int m1 = nums[nums.size() / 2 - 1];
            int m2 = nums[nums.size() / 2];
            return std::min(calculateMoves(nums, m1),
                            calculateMoves(nums, m2));
        }
    }

    int calculateMoves(vector<int>& nums, int target){
        int cost = 0;
        std::for_each(nums.begin(), nums.end(),
                      [&](int x){cost += abs(x - target);});
        return cost;
    }
};
