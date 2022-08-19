// ****************************************************************************
// 
// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//
// ----------------------------------------------------------------------------
//
//
// Given a string containing digits from 2-9 inclusive, return all possible
// letter combinations that the number could represent.
// Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is
// given below. Note that 1 does not map to any letters.
// 
// Example 1:
// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 
// Example 2:
// Input: digits = ""
// Output: []
// 
// Example 3:
// Input: digits = "2"
// Output: ["a","b","c"]
// 
// Constraints:
//     * 0 <= digits.length <= 4
//     * digits[i] is a digit in the range ['2', '9'].


#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};
        else if (digits.size() == 1){
            std::vector<string> result;
            int i = digits[0] - '2';
            for (char c : phone[i])
                result.push_back(string(1, c));
            return result;
        }
        else {
            vector<string> rest = letterCombinations(digits.substr(1));
            vector<string> result;
            int i = digits[0] - '2';
            std::stringstream ss;
            for (const char c : phone[i]){
                for (const string& s : rest){
                    ss << c << s;
                    result.push_back(ss.str());
                    ss.str("");
                }
            }
            return result;
        }
    }
private:
    static const string phone[8];
};


const string Solution::phone[8] = {
        "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
};
