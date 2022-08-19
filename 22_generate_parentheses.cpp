// ****************************************************************************
// 
// 22. Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/
//
// ----------------------------------------------------------------------------
//
//
// Given n pairs of parentheses, write a function to generate all
// combinations of well-formed parentheses.
// 
// 
// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// 
// Example 2:
// Input: n = 1
// Output: ["()"]
// 
// Constraints:
//     * 1 <= n <= 8



#include <string>
#include <sstream>
#include <unordered_set>
#include <vector>

using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0)
            return {""};
        else if (n == 1)
            return {"()"};
        else {
            std::unordered_set<string> result;
            std::stringstream ss;
            for (int j = 1; j <= n; j++){
                vector<string> left = generateParenthesis(j - 1);
                vector<string> right = generateParenthesis(n - j);
                for (const string& l : left){
                    for (const string& r : right){
                        ss << "(" << l << ")" << r;
                        result.insert(ss.str());
                        ss.str("");
                    }
                }
            }
            return vector(result.begin(), result.end());
        }
    }
};
