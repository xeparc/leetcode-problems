//////////////////////////////////////////////////////////////////////////////
//
// 784. Letter Case Permutation
// https://leetcode.com/problems/letter-case-permutation/
//
// ***************************************************************************


// Given a string S, we can transform every letter individually
// to be lowercase or uppercase to create another string.

// Return a list of all possible strings we could create.
// You can return the output in any order.

// Example 1:
// Input: S = "a1b2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]

// Example 2:
// Input: S = "3z4"
// Output: ["3z4","3Z4"]

// Example 3:
// Input: S = "12345"
// Output: ["12345"]

// Example 4:
// Input: S = "0"
// Output: ["0"]


// Constraints:
// * S will be a string with length between 1 and 12.
// * S will consist only of letters or digits.



#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        std::transform(S.begin(), S.end(), S.begin(), [](const char c){ return std::tolower(c);});
        vector<string> result {S};
        backtrack(S, 0, result);
        return result;
    }

    void backtrack(string S, size_t pos, vector<string>& permutations){
        if (pos == S.size())
            return;
        for (size_t i = pos; i < S.size(); i++){
            if (std::isalpha(S[i])){
                S[i] = std::toupper(S[i]);
                permutations.push_back(S);
                backtrack(S, i + 1, permutations);
                S[i] = std::tolower(S[i]);
            }
        }
    }
};
