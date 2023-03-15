// ///////////////////////////////////////////////////////////////////////////
//
// 2207. Maximize Number of Subsequences in a String
// https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/description/
// 
// ***************************************************************************
//
//
// You are given a 0-indexed string text and another 0-indexed string pattern
// of length 2, both of which consist of only lowercase English letters.
// You can add either pattern[0] or pattern[1] anywhere in text exactly once.
// Note that the character can be added even at the beginning or at the end of text.
// Return the maximum number of times pattern can occur as a subsequence
// of the modified text.
// 
// A subsequence is a string that can be derived from another string by
// deleting some or no characters without changing the order of the
// remaining characters.
// 
// 
// Example 1:
// Input: text = "abdcdbc", pattern = "ac"
// Output: 4
// Explanation:
// If we add pattern[0] = 'a' in between text[1] and text[2], we get "abadcdbc".
// Now, the number of times "ac" occurs as a subsequence is 4.
// Some other strings which have 4 subsequences "ac" after adding a character
// to text are "aabdcdbc" and "abdacdbc".
// However, strings such as "abdcadbc", "abdccdbc", and "abdcdbcc", although
// obtainable, have only 3 subsequences "ac" and are thus suboptimal.
// It can be shown that it is not possible to get more than 4 subsequences
// "ac" by adding only one character.
// 
// Example 2:
// Input: text = "aabb", pattern = "ab"
// Output: 6
// Explanation:
// Some of the strings which can be obtained from text and have 6 subsequences
// "ab" are "aaabb", "aaabb", and "aabbb".
// 
// Constraints:
//     * 1 <= text.length <= 10^5
//     * pattern.length == 2
//     * text and pattern consist only of lowercase English letters.



#include <string>
using namespace std;


class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        // Special case
        if (pattern[0] == pattern[1]){
            long long n = 0;
            for (char c : text)
                if (c == pattern[0]) n++;
            return ((n + 1) * n) / 2;
        }
        long long n = 1, m = 1;
        long long sumA = 0;     // if pattern[0] is placed at index 0
        long long sumB = 0;     // if pattern[1] is placed at index text.size()
        for (int i = 0; i < text.size(); i++){
            // sumA loop
            if (text[i] == pattern[0])
                n++;
            else if (text[i] == pattern[1])
                sumA += n;

            // sumB loop
            int j = text.size() - 1 - i;
            if (text[j] == pattern[1])
                m++;
            else if (text[j] == pattern[0])
                sumB += m;
        }
        return sumA < sumB ? sumB : sumA;
    }
};
