# ############################################################################
#
# 954. Array of Doubled Pairs
# https://leetcode.com/problems/array-of-doubled-pairs/
#
# ############################################################################
#
#
# Given an integer array of even length arr, return true if it is
# possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i]
# for every 0 <= i < len(arr) / 2, or false otherwise.
#
#
# Example 1:
# Input: arr = [3,1,3,6]
# Output: false
#
# Example 2:
# Input: arr = [2,1,2,6]
# Output: false
#
# Example 3:
# Input: arr = [4,-2,2,-4]
# Output: true
# Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
#
# Example 4:
# Input: arr = [1,2,4,16,8,4]
# Output: false
#
# Constraints:
# 2 <= arr.length <= 3 * 10^4
# arr.length is even.
# -10^5 <= arr[i] <= 10^5


from collections import Counter
from typing import List

class Solution:
    def canReorderDoubled(self, arr: List[int]) -> bool:
        arr = sorted(arr)
        counts = Counter(arr)
        pairs = 0
        for a in arr:
            if a == 0:
                if counts[a] >= 2:
                    pairs += 1
                    counts[a] -= 2
            elif counts[a] and counts[2 * a]:
                pairs += 1
                counts[a] -= 1
                counts[2 * a] -= 1
        return pairs == len(arr) // 2
