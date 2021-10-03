# ############################################################################
#
# 593. Valid Square
# https://leetcode.com/problems/valid-square/
# 
# ############################################################################

# Given the coordinates of four points in 2D space,
# return whether the four points could construct a square.
# The coordinate (x,y) of a point is represented by an integer array
# with two integers.


# Example:

# Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
# Output: True


# Note:

# All the input integers are in the range [-10000, 10000].
# A valid square has four equal sides with positive length and four
# equal angles (90-degree angles).
# Input points have no order.



import math

class Solution:
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        distances = []
        points = [p1, p2, p3, p4]
        for i in range(4):
            for j in range(i + 1, 4):
                distances.append(euclidean(points[i], points[j]))
        unique = set(distances)
        if len(unique) != 2:
            return False
        a, b = min(unique), max(unique)
        return math.isclose(b, a * math.sqrt(2))


def euclidean(p1, p2):
    return ((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2) ** 0.5
