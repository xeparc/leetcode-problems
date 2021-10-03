# ############################################################################
#
# 187. Repeated DNA Sequences
# https://leetcode.com/problems/repeated-dna-sequences/
# 
# ############################################################################


# All DNA is composed of a series of nucleotides abbreviated
# as 'A', 'C', 'G', and 'T', for example: "ACGAATTCCG".
# When studying DNA, it is sometimes useful to identify
# repeated sequences within the DNA.

# Write a function to find all the 10-letter-long sequences
# (substrings) that occur more than once in a DNA molecule.


# Example 1:

# Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
# Output: ["AAAAACCCCC","CCCCCAAAAA"]


# Example 2:

# Input: s = "AAAAAAAAAAAAA"
# Output: ["AAAAAAAAAA"]


# Constraints:

# 0 <= s.length <= 10^5
# s[i] is 'A', 'C', 'G', or 'T'.



from typing import List

class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        root = {}
        result = []
        result_set = set()
        for i in range(0, len(s) - 9):
            curr = root
            repeats = True
            for j in range(10):
                c = s[i + j]
                if c not in curr:
                    repeats = False
                    curr[c] = {}
                curr = curr[c]
            if repeats and s[i:i+10] not in result_set:
                substr = s[i:i+10]
                result.append(substr)
                result_set.add(substr)
        return result
