//////////////////////////////////////////////////////////////////////////////
//
// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water/
//
// ***************************************************************************


// Given n non-negative integers a1, a2, ..., an , where each represents a
// point at coordinate (i, ai). n vertical lines are drawn such that the two
// endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which,
// together with the x-axis forms a container, such that the container
// contains the most water.

// Notice that you may not slant the container.


// Example 1:
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49

// Example 2:
// Input: height = [1,1]
// Output: 1

// Example 3:
// Input: height = [4,3,2,1,4]
// Output: 16

// Example 4:
// Input: height = [1,2,1]
// Output: 2


// Constraints:

// * n == height.length
// * 2 <= n <= 3 * 10^4
// * 0 <= height[i] <= 3 * 10^4



#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i != j){
            int area = (j - i) * std::min(height[i], height[j]);
            max_area = std::max(max_area, area);
            if (height[i] < height[j])
                i++;
            else if (height[i] > height[j])
                j--;
            else {
                if (height[i + 1] >= height[j - 1])
                    i++;
                else
                    j--;
            }
        }
        return max_area;
    }

    int maxAreaBruteForce(vector<int>& height){
        vector<int> ys {height[0]};
        vector<int> xs {0};
        int max_area = 0;
        for (int i = 0; i < height.size(); i++){
            // calculate all max rectangles so far
            for (int j = 0; j < ys.size(); j++){
                int area = (i - xs[j]) * std::min(height[i], ys[j]);
                max_area = std::max(area, max_area);
                if (ys[j] > height[i])
                    break;
            }
            if (height[i] > ys.back()){
                ys.push_back(height[i]);
                xs.push_back(i);
            }
        }
        return max_area;
    }
};
