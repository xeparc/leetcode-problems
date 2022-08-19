# ############################################################################
#
# 6. Zigzag Conversion
# https://leetcode.com/problems/zigzag-conversion/
# 
# ############################################################################
# 
# 
# The string "PAYPALISHIRING" is written in a zigzag pattern on a given
# number of rows like this: (you may want to display this pattern in a
# fixed font for better legibility)
# 
# P   A   H   N
# A P L S I I G
# Y   I   R
# 
# And then read line by line: "PAHNAPLSIIGYIR"
# 
# Write the code that will take a string and make this conversion given
# a number of rows:
#     string convert(string s, int numRows);



from itertools import cycle


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        rows = [[] for _ in range(numRows)]
        it = cycle(list(range(numRows)) + list(reversed(range(1, numRows-1))))
        for i, c in zip(it, s):
            rows[i].append(c)
        return ''.join(''.join(r) for r in rows)
