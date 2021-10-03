//////////////////////////////////////////////////////////////////////////////
//
// 645. Set Mismatch
// hhttps://leetcode.com/problems/set-mismatch/
//
// ***************************************************************************


// You have a set of integers s, which originally contains all the numbers
// from 1 to n. Unfortunately, due to some error, one of the numbers in s got
// duplicated to another number in the set, which results in repetition of
// one number and loss of another number.

// You are given an integer array nums representing the data status of
// this set after the error.

// Find the number that occurs twice and the number that is missing
// and return them in the form of an array.


// Example 1:
// Input: nums = [1,2,2,4]
// Output: [2,3]

// Example 2:
// Input: nums = [1,1]
// Output: [1,2]

// Constraints:
// 2 <= nums.length <= 10^4
// 1 <= nums[i] <= 10^4



#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int duplicated = -1;
        int missing = nums.size();
        bool flag = false;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i - 1]){
                duplicated = nums[i];
                break;
            }
        }
        for (int i = 0, j = 1; i < nums.size(); j++){
            if (nums[i] != j){
                missing = j;
                break;
            }
            while (i < nums.size() && nums[i] == j){
                i++;
            }
        }
        return {duplicated, missing};
    }

    vector<int> findErrorNumsLinearTime(vector<int>& nums) {
        int duplicated = -1;
        int missing = nums.size();
        for (size_t i = 0; i < nums.size(); i++){
            int k = abs(nums[i]) - 1;
            if (nums[k] < 0)
                duplicated = k + 1;
            else
                nums[k] = -nums[k];
        }
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0)
                missing = i + 1;
        return {duplicated, missing};
    }
};
