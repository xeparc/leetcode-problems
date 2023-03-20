// ///////////////////////////////////////////////////////////////////////////
//
// 42. Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/description/
// ***************************************************************************
//
//
// Given n non-negative integers representing an elevation map where the
// width of each bar is 1, compute how much water it can trap after raining.
// 
// Example 1:
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by
// array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water
// (blue section) are being trapped.
// 
// Example 2:
// Input: height = [4,2,0,3,2,5]
// Output: 9
// 
// Constraints:
//     * n == height.length
//     * 1 <= n <= 2 * 10^4
//     * 0 <= height[i] <= 10^5



#include <vector>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> highest_left(height.size(), 0);
        vector<int> highest_right(height.size(), 0);
        int hL = 0, hR = 0;
        for (int i = 0; i < height.size(); i++){
            highest_left[i] = hL;
            hL = max(hL, height[i]);
        }
        for (int i = height.size() - 1; i >= 0; i--){
            highest_right[i] = hR;
            hR = max(hR, height[i]);
        }
        int trapped = 0;
        for (int i = 0; i < height.size(); i++){
            trapped += max(0, min(highest_left[i], highest_right[i]) - height[i]);
        }
        return trapped;
    }
};
