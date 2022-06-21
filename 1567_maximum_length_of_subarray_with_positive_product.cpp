// ///////////////////////////////////////////////////////////////////////////
//
// 1567. Maximum Length of Subarray With Positive Product
// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
//
// ***************************************************************************
//
//
// Given an array of integers nums, find the maximum length of a subarray
// where the product of all its elements is positive.
// A subarray of an array is a consecutive sequence of zero or more values
// taken out of that array.
// Return the maximum length of a subarray with positive product.
// 
// 
// Example 1:
// Input: nums = [1,-2,-3,4]
// Output: 4
// Explanation: The array nums already has a positive product of 24.
// 
// Example 2:
// Input: nums = [0,1,-2,-3,-4]
// Output: 3
// Explanation: The longest subarray with positive product is [1,-2,-3]
//     which has a product of 6. Notice that we cannot include 0 in the subarray
//     since that'll make the product 0 which is not positive.
// 
// Example 3:
// Input: nums = [-1,-2,-3,0,1]
// Output: 2
// Explanation: The longest subarray with positive product is [-1,-2] or [-2,-3]. 
// 
// Constraints:
//     *   1 <= nums.length <= 10^5
//     *   -10^9 <= nums[i] <= 10^9



#include <algorithm>
#include <vector>

using namespace std;


int sign(int x)
{
    return x >> 31 == 0 ? 1 : -1; 
}


class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int maxlen = 0;
        int pos_prod_len = 0;
        int neg_prod_len = 0;
        for (int j = 0; j < nums.size(); j++){
            if (nums[j] == 0){
                pos_prod_len = 0;
                neg_prod_len = 0;
            }
            else {
                int s = sign(nums[j]);
                if (s == 1){
                    pos_prod_len++;
                    if (neg_prod_len > 0)
                        neg_prod_len++;
                }
                else if (s == -1) {
                    std::swap(pos_prod_len, neg_prod_len);
                    neg_prod_len++;
                    if (pos_prod_len > 0)
                        pos_prod_len++;
                }
            }
            maxlen = std::max(maxlen, pos_prod_len);
        }
        return maxlen;
    }
};
