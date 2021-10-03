#include <algorithm>

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        size_t remaining = intervals.size();
        std::sort(intervals.begin(), intervals.end(),
                 [](const vector<int>& A, const vector<int>& B){
                     if (A[0] < B[0])
                         return true;
                     else if (A[0] == B[0])
                         return A[1] >= B[1];
                     return false;
                 });
        vector<int> last = intervals[0];
        for (size_t i = 1; i < intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if ((last[0] <= start) and (end <= last[1]))
                remaining--;
            else
                last = intervals[i];
        }
        return remaining;
    }
};




#include <algorithm>

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        size_t remaining = intervals.size();
        std::sort(intervals.begin(), intervals.end(),
                 [](const vector<int>& A, const vector<int>& B){
                     return (A[0] < B[0]) or (A[0] == B[0] and A[1] >= B[1]);
                 });
        vector<int> last = intervals[0];
        for (size_t i = 1; i < intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if ((last[0] <= start) and (end <= last[1]))
                remaining--;
            else
                last = intervals[i];
        }
        return remaining;
    }
};


