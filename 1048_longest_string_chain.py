# *****************************************************************************
#
# 1048. Longest String Chain
# https://leetcode.com/problems/longest-string-chain/
# 
# *****************************************************************************
# 
# 
# Given a list of words, each word consists of English lowercase letters.
# Let's say word1 is a predecessor of word2 if and only if we can add exactly
# one letter anywhere in word1 to make it equal to word2.
# For example, "abc" is a predecessor of "abac".
# A word chain is a sequence of words [word_1, word_2, ..., word_k]
# with k >= 1, where word_1 is a predecessor of word_2, word_2 is a
# predecessor of word_3, and so on.
# Return the longest possible length of a word chain with words chosen
# from the given list of words.
# 
# 
# Example 1:
# 
# Input: words = ["a","b","ba","bca","bda","bdca"]
# Output: 4
# Explanation: One of the longest word chain is "a","ba","bda","bdca".
# 
# 
# Example 2:
# 
# Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
# Output: 5
# 
# 
# Constraints:
# 
# 1 <= words.length <= 1000
# 1 <= words[i].length <= 16
# words[i] only consists of English lowercase letters.



class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        W = dict.fromkeys(words, 1)
        words.sort(key=len, reverse=True)
        for w in words:
            predescessors = set()
            for i in range(len(w)):
                predescessors.add(w[:i] + w[i + 1:])
            for p in predescessors:
                try:
                    W[p] = max(W[p], W[w] + 1)
                except KeyError:
                    pass
        # print(W)
        return max(W.values())
