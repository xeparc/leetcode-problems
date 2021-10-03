// ****************************************************************************
// 
// 5. Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/
//
// ----------------------------------------------------------------------------

// Given a string s, find the longest palindromic substring in s.
// You may assume that the maximum length of s is 1000.

// Example 1:
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.

// Example 2:
// Input: "cbbd"
// Output: "bb"

#include <utility>

std::pair<int, int> expand_at(string s, int i);
std::pair<int, int> expand_middle(string s, int i);
std::pair<int, int> expand(string, int, int);


//
// First solution
// **************
class Solution {
public:
    string longestPalindrome(string s) {
        std::pair<int, int> longest{0, 0};
        
        for (int i = 1; i < s.size(); i++){
            auto palindrome = expand_at(s, i - 1);
            if (palindrome.second > longest.second)
                longest = palindrome;
            palindrome = expand_middle(s, i);
            if (palindrome.second > longest.second)
                longest = palindrome;
        }
        // Check the last index
        auto palindrome = expand_at(s, s.size() - 1);
            if (palindrome.second > longest.second)
                longest = palindrome;
        
        return s.substr(longest.first, longest.second);
    }
};


//
// Refactored (hints from Leetcode)
// ********************************
class Solution {
public:
    string longestPalindrome(string s) {
        std::pair<int, int> longest{0, 0};
        std::pair<int, int> palindrome;
        for (int i = 0; i < s.size(); i++){
            palindrome = expand(s, i, i);
            if (palindrome.second > longest.second)
                longest = palindrome;
            palindrome = expand(s, i, i + 1);
            if (palindrome.second > longest.second)
                longest = palindrome;
        }
        return s.substr(longest.first, longest.second);
    }
};


// Expands palindrome string with center between `i` and `j`
// (Note: i can == j, in this case the center is s[i])
// Returns {start index, length} pair of the longest
// palindrome substring.
std::pair<int, int> expand(string s, int i, int j){
    for (; i >= 0 and j < s.size() and s[i] == s[j]; i--, j++);
    return std::pair<int, int>{i + 1, j - i - 1};
}

// Expands palindrome string centered at index `i` of `s`
// Returns {start index, length} pair of the longest
// palindrome substring.
std::pair<int, int> expand_at(string s, int i){
    int j = i;
    for (; i >= 0 and j < s.size() and s[i] == s[j]; i--, j++);
    return std::pair<int, int>{i + 1, j - i - 1};
}


// Expands palindrome string centered between index `i - 1`
// and `i`. Returns {start index, length} pair of
// the longest palindrome substring.
std::pair<int, int> expand_middle(string s, int i){
    int j = i - 1;
    for (; j >= 0 and i < s.size() and s[j] == s[i]; j--, i++);
    return std::pair<int, int>{j + 1, i - j - 1};
}