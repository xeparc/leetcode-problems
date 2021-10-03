from itertools import islice

class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda i: (i[0], -i[1]))
        remaining = len(intervals)
        last = intervals[0]
        for x in islice(intervals, 1, None):
            if last[0] <= x[0] and x[1] <= last[1]:
                remaining -= 1
            else:
                last = x
        return remaining


