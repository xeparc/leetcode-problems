# *****************************************************************************
#
# 41. First Missing Positive
# https://leetcode.com/problems/first-missing-positive/
# 
# *****************************************************************************

# Given an unsorted integer array, find the smallest missing positive integer.

# Example 1:
# Input: [1,2,0]
# Output: 3

# Example 2:
# Input: [3,4,-1,1]
# Output: 2

# Example 3:
# Input: [7,8,9,11,12]
# Output: 1

# Follow up:
# Your algorithm should run in O(n) time and uses constant extra space.

from typing import List

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        N = len(nums)
        for i, n in enumerate(nums):
            if n < 0:
                nums[i] = 0
        for i, n in enumerate(nums):
            if 0 < abs(n) <= N:
                j = abs(n) - 1
                if nums[j] == 0:
                    nums[j] = -N - 1
                elif nums[j] > 0:
                    nums[j] = -nums[j]
        for i, n in enumerate(nums, 1):
            if n >= 0:
                return i
        return N + 1
