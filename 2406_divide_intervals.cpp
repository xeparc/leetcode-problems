// ****************************************************************************
// 
// 2406. Divide Intervals Into Minimum Number of Groups
// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/
//
// ----------------------------------------------------------------------------
//
//
// You are given a 2D integer array intervals where intervals[i] = [lefti, righti]
// represents the inclusive interval [lefti, righti].
// You have to divide the intervals into one or more groups such that each
// interval is in exactly one group, and no two intervals that are in the
// same group intersect each other.
// Return the minimum number of groups you need to make.
// Two intervals intersect if there is at least one common number between them.
// For example, the intervals [1, 5] and [5, 8] intersect.
// 
// 
// Example 1:
// Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
// Output: 3
// Explanation: We can divide the intervals into the following groups:
// - Group 1: [1, 5], [6, 8].
// - Group 2: [2, 3], [5, 10].
// - Group 3: [1, 10].
// It can be proven that it is not possible to divide the intervals
// into fewer than 3 groups.
// 
// 
// Example 2:
// Input: intervals = [[1,3],[5,6],[8,10],[11,13]]
// Output: 1
// Explanation: None of the intervals overlap, so we can put all of them
// in one group.
//  
// 
// Constraints:
//     * 1 <= intervals.length <= 10^5
//     * intervals[i].length == 2
//     * 1 <= lefti <= righti <= 10^6



#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    /*
    REALLY SMART HINT !!! Never tought of that :/
    The minimum number of groups we need is equivalent to the maximum number
    of intervals that overlap at some point. How can you find that?
    */
    int minGroups(vector<vector<int>>& intervals) {
        std::vector<int> groups;
        std::sort(
            intervals.begin(),
            intervals.end(),
            [](const vector<int>& i1, const vector<int>& i2) {
                return i1[0] < i2[0];
            }
        );
        for (const auto& I : intervals){
            int left = I[0];
            int right = I[1];
            if (!groups.empty()){
                int R = -groups[0];
                if (R < left){
                    std::pop_heap(groups.begin(), groups.end());
                    groups.pop_back();
                }
            }
            groups.push_back(-right);
            std::push_heap(groups.begin(), groups.end());
        }
        return groups.size();
    }
};
