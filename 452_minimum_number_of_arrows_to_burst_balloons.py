# ############################################################################
#
# 452. Minimum Number of Arrows to Burst Balloons
# https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
# 
# ############################################################################

import itertools
from typing import List

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if not points:
            return 0
        points.sort()
        overlapping = 0
        current = points[0]
        for p in itertools.islice(points, 1, None):
            if p[0] <= current[1]:  # intervals overlap
                current[0] = p[0]
                current[1] = min(p[1], current[1])
            else:
                overlapping += 1
                current = p
        return overlapping + 1