// ****************************************************************************
// 
// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/
//
// ----------------------------------------------------------------------------
//
//
// Given a string s containing just the characters '(', ')', '{', '}',
// '[' and ']', determine if the input string is valid.
// An input string is valid if:
//     Open brackets must be closed by the same type of brackets.
//     Open brackets must be closed in the correct order.
// 
// 
// Example 1:
// Input: s = "()"
// Output: true
// 
// Example 2:
// Input: s = "()[]{}"
// Output: true
// 
// Example 3:
// Input: s = "(]"
// Output: false
// 
// Constraints:
//     * 1 <= s.length <= 104
//     * s consists of parentheses only '()[]{}'.



#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        std::stack<char> S;
        for (char c : s){
            switch (c){
                case '(':
                case '[':
                case '{':
                    {
                        S.push(c);
                        break;
                    }
                case ')':
                case ']':
                case '}':
                    {
                        if (S.empty() || S.top() != getOpen(c))
                            return false;
                        S.pop();
                        break;
                    }
                default:
                    return false;
            }
        }
        return S.empty();
    }

    char getOpen(char bracket) {
        switch (bracket){
            case ']':
                return '[';
            case ')':
                return '(';
            case '}':
                return '{';
            default:
                return 0;
        }
    }
};
