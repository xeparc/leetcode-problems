// ****************************************************************************
// 
// 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/
// 
// ----------------------------------------------------------------------------


// Given a collection of intervals, merge all overlapping intervals.

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

// NOTE: input types have been changed on April 15, 2019.
// Please reset to default code definition to get new method signature.

// Constraints:
// intervals[i][0] <= intervals[i][1]



#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return intervals;
        std::sort(intervals.begin(), intervals.end(),
                  [](const vector<int>& a, const vector<int>& b){
                      return a[0] < b[0];
                  });
        vector<vector<int>> result;
        int start = intervals[0][0];
        int end   = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] <= end)
                end = std::max(end, intervals[i][1]);
            else {
                result.emplace_back(vector<int>{start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        result.emplace_back(vector<int>{start, end});
        return result;
    }
};
