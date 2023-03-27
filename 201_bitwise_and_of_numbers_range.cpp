// ///////////////////////////////////////////////////////////////////////////
//
// 201. Bitwise AND of Numbers Range
// https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
// 
// ***************************************************************************
//
//
// Given two integers left and right that represent the range [left, right],
// return the bitwise AND of all numbers in this range, inclusive.
// 
// 
// Example 1:
// Input: left = 5, right = 7
// Output: 4
// 
// Example 2:
// Input: left = 0, right = 0
// Output: 0
// 
// Example 3:
// Input: left = 1, right = 2147483647
// Output: 0
// 
// Constraints:
//     * 0 <= left <= right <= 2^31 - 1



class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int result = 0;
        while (left > 0 && right > 0){
            int msbL = msBit(left);
            int msbR = msBit(right);
            if (msbL == msbR){
                result = result | msbL;
                left = left ^ msbL;
                right = right ^ msbR;
            } else
                break;
        }
        return result;
    }

    int msBit(int a){
        unsigned int x = 1 << 30;
        while ((x & a) == 0){
            x = (x >> 1);
        }
        return x;
    }
};
