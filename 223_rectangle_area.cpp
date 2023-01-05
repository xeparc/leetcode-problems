// ///////////////////////////////////////////////////////////////////////////
//
// 223. Rectangle Area
// https://leetcode.com/problems/rectangle-area/description/
//
// ***************************************************************************
//
//
// Given the coordinates of two rectilinear rectangles in a 2D plane,
// return the total area covered by the two rectangles.
// The first rectangle is defined by its bottom-left corner (ax1, ay1) and
// its top-right corner (ax2, ay2).
// The second rectangle is defined by its bottom-left corner (bx1, by1) and
// its top-right corner (bx2, by2).
// 
// Example 1:
// Input: ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
// Output: 45
// 
// Example 2:
// Input: ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
// Output: 16

#include <algorithm>
#include <array>
#include <utility>


class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // Calculate the area of intersection
        using PIndex = std::pair<int, int>;
        std::array<std::pair<int, int>, 4> xs = {
            PIndex(ax1, 0), PIndex(ax2, 0), PIndex(bx1, 1), PIndex(bx2, 1)
        };
        std::array<std::pair<int, int>, 4> ys = {
            PIndex(ay1, 0), PIndex(ay2, 0), PIndex(by1, 1), PIndex(by2, 1)
        };
        std::sort(xs.begin(), xs.end());
        std::sort(ys.begin(), ys.end());
        int width = 0;
        int height = 0;
        if ((xs[2].second == xs[0].second) || (xs[3].second == xs[0].second)){
            width = xs[2].first - xs[1].first;
        }
        if ((ys[2].second == ys[0].second) || (ys[3].second == ys[0].second)){
            height = ys[2].first - ys[1].first;
        }
        // Calculate the sum of areas
        int areaA = abs(ax2 - ax1) * abs(ay2 - ay1);
        int areaB = abs(bx2 - bx1) * abs(by2 - by1);
        // Calculate the area of the union
        return areaA + areaB - (width * height);
    }

    int computeAreaFast(int ax1, int ay1, int ax2, int ay2,
                        int bx1, int by1, int bx2, int by2)
    {
        int areaA = abs(ax2 - ax1) * abs(ay2 - ay1);
        int areaB = abs(bx2 - bx1) * abs(by2 - by1);
        // Calculate width & height of intersection
        int width = std::max(0, std::min(ax2, bx2) - std::max(ax1, bx1));
        int height = std::max(0, std::min(ay2, by2) - std::max(ay1, by1));
        return areaA + areaB - (width * height);
    }
};
