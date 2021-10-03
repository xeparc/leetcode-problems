# ############################################################################
#
# 49. Group Anagrams
# https://leetcode.com/problems/group-anagrams/
#
# ############################################################################
#
#
# Given an array of strings strs, group the anagrams together.
# You can return the answer in any order. An Anagram is a word or phrase
# formed by rearranging the letters of a different word or phrase,
# typically using all the original letters exactly once.
#
#
# Example 1:
# Input: strs = ["eat","tea","tan","ate","nat","bat"]
# Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
#
# Example 2:
# Input: strs = [""]
# Output: [[""]]
#
# Example 3:
# Input: strs = ["a"]
# Output: [["a"]]
#
# Constraints:
# 1 <= strs.length <= 10^4
# 0 <= strs[i].length <= 100
# strs[i] consists of lower-case English letters.


from itertools import groupby
from functools import reduce
from operator import mul
from typing import List

# First solution
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        k = lambda s: sorted(s)
        S = sorted(strs, key=k)
        result = []
        for k, g in groupby(S, key=k):
            result.append(list(g))
        return result

# Clever solution in comments, but slower
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        primes = {'a': 2,
                  'b': 3,
                  'c': 5,
                  'd': 7,
                  'e': 11,
                  'f': 13,
                  'g': 17,
                  'h': 19,
                  'i': 23,
                  'j': 29,
                  'k': 31,
                  'l': 37,
                  'm': 41,
                  'n': 43,
                  'o': 47,
                  'p': 53,
                  'q': 59,
                  'r': 61,
                  's': 67,
                  't': 71,
                  'u': 73,
                  'v': 79,
                  'w': 83,
                  'x': 89,
                  'y': 97,
                  'z': 101
                 }
        key = lambda s: reduce(mul, (primes[c] for c in s), 1)
        result = []
        for _, g in groupby(sorted(strs, key=key), key=key):
            result.append(list(g))
        return result
