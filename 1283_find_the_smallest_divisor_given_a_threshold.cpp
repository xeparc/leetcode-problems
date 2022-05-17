// ///////////////////////////////////////////////////////////////////////////
//
// 1283. Find the Smallest Divisor Given a Threshold
// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
//
// ***************************************************************************
//
//
// Given an array of integers nums and an integer threshold, we will choose
// a positive integer divisor, divide all the array by it, and sum the
// division's result. Find the smallest divisor such that the result
// mentioned above is less than or equal to threshold.
// Each result of the division is rounded to the nearest integer greater
// than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
// The test cases are generated so that there will be an answer.
//
// Example 1:
// Input: nums = [1,2,5,9], threshold = 6
// Output: 5
// Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1.
// If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor
// is 5 the sum will be 5 (1+1+1+2).
//
// Example 2:
// Input: nums = [44,22,33,11,1], threshold = 5
// Output: 44
//
// Constraints:
// 1 <= nums.length <= 5 * 10^4
// 1 <= nums[i] <= 10^6
// nums.length <= threshold <= 10^6



#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;


class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long sum = std::accumulate(nums.begin(), nums.end(), 0L);
        long lo = std::max(1L, sum / threshold);
        long hi = std::ceil(sum * static_cast<float>(threshold) / nums.size());

        while (lo < hi){
            long m  = lo + (hi - lo) / 2;
            long S = divide_and_sum(nums, m);
            if (S > threshold)
                lo = m + 1;
            else
                hi = m;
        }
        return lo;
    }

    long divide_and_sum(vector<int>& nums, int div){
        // Plain For loop is faster than std::transform_reduce()
        long acc = 0L;
        for (int x : nums)
            acc += x / div + static_cast<int>(x % div > 0);
        return acc;
        // return std::transform_reduce(
        //     nums.begin(),
        //     nums.end(),
        //     0L,
        //     std::plus<long>(),
        //     [=](const long x) -> long { return x / div + (x % div > 0); }
        // );
    }
};
