// ****************************************************************************
// 
// 290. Word Pattern
// https://leetcode.com/problems/word-pattern/
//
// ----------------------------------------------------------------------------


// Given a pattern and a string str, find if str follows the same pattern.
// Here follow means a full match, such that there is a bijection between
// a letter in pattern and a non-empty word in str.

// Example 1:
// Input: pattern = "abba", str = "dog cat cat dog"
// Output: true

// Example 2:
// Input: pattern = "abba", str = "dog cat cat fish"
// Output: false

// Example 3:
// Input: pattern = "aaaa", str = "dog cat cat dog"
// Output: false

// Example 4:
// Input: pattern = "abba", str = "dog dog dog dog"
// Output: false

// Notes:
// You may assume pattern contains only lowercase letters, and str contains
// lowercase letters that may be separated by a single space.



#include <array>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        array<int, 26>   char_map{};
        unordered_map<string, int> word_map;
        istringstream istream(str); 
        int i = 0, N = pattern.size();
        for (string token; istream >> token; i++){
            if (i == N)
                return false;
            size_t j = pattern[i] - 'a';
            if (!char_map[j] && !word_map[token])
                char_map[j] = word_map[token] = i + 1;
            else if (char_map[j] != word_map[token])
                return false;
        }
        return i == N;
    }
};
