// ****************************************************************************
// 
// 497. Random Point in Non-overlapping Rectangles
// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/
//
// ----------------------------------------------------------------------------

// Given a list of non-overlapping axis-aligned rectangles rects, write a
// function pick which randomly and uniformily picks an integer point
// in the space covered by the rectangles.

// Note:

// An integer point is a point that has integer coordinates. 
// A point on the perimeter of a rectangle is included in the space
// covered by the rectangles. 
// ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the
// integer coordinates of the bottom-left corner, and [x2, y2]
// are the integer coordinates of the top-right corner.

// length and width of each rectangle does not exceed 2000.
// 1 <= rects.length <= 100
// pick return a point as an array of integer coordinates [p_x, p_y]
// pick is called at most 10000 times.

// Example 1:
// Input: 
// ["Solution","pick","pick","pick"]
// [[[[1,1,5,5]]],[],[],[]]
// Output: 
// [null,[4,1],[4,1],[3,3]]

// Example 2:
// Input: 
// ["Solution","pick","pick","pick","pick","pick"]
// [[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
// Output: 
// [null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]

#include <random>
#include <algorithm>
#include <numeric>


class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        rectangles = rects;
        std::vector<int> areas;
        // Stupid fools think that a rectangle with zero area (such as line)
        // has non-zero probbility of being selected.
        std::transform(rects.begin(), rects.end(),
                       std::back_inserter(areas),
                       [](const vector<int>& r){
                           return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);}
                      );
        dist = std::discrete_distribution<int>(areas.begin(), areas.end());
    }
    
    vector<int> pick() {
        // Pick rectangle
        auto& r = rectangles[dist(rng)];
        std::uniform_int_distribution xdist(r[0], r[2]);
        std::uniform_int_distribution ydist(r[1], r[3]);
        return std::vector<int>{xdist(rng), ydist(rng)};
        
    }

private:
    std::mt19937_64 rng {};
    std::vector<std::vector<int>> rectangles;
    std::discrete_distribution<int> dist;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */