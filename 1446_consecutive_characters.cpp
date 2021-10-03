//////////////////////////////////////////////////////////////////////////////
//
// 1446. Consecutive Characters
// https://leetcode.com/problems/consecutive-characters/
//
// ***************************************************************************


// Given a string s, the power of the string is the maximum length of a
// non-empty substring that contains only one unique character.
// Return the power of the string.


// Example 1:
// Input: s = "leetcode"
// Output: 2
// Explanation: The substring "ee" is of length 2 with the character 'e' only.

// Example 2:
// Input: s = "abbcccddddeeeeedcba"
// Output: 5
// Explanation: The substring "eeeee" is of length 5 with the character 'e' only.

// Example 3:
// Input: s = "triplepillooooow"
// Output: 5

// Example 4:
// Input: s = "hooraaaaaaaaaaay"
// Output: 11

// Example 5:
// Input: s = "tourist"
// Output: 1
 

// Constraints:

// 1 <= s.length <= 500
// s contains only lowercase English letters.



#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        char prev = 0;
        int power = 0;
        int maxpower = 0;
        for (char c : s){
            if (c == prev){
                power++;
            } else {
                maxpower = std::max(power, maxpower);
                prev = c;
                power = 1;   
            }
        }
        return std::max(power, maxpower);
    }
};
