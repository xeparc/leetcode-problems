//////////////////////////////////////////////////////////////////////////////
//
// 187. Repeated DNA Sequences
// https://leetcode.com/problems/repeated-dna-sequences/
//
// ***************************************************************************


// All DNA is composed of a series of nucleotides abbreviated
// as 'A', 'C', 'G', and 'T', for example: "ACGAATTCCG".
// When studying DNA, it is sometimes useful to identify
// repeated sequences within the DNA.

// Write a function to find all the 10-letter-long sequences
// (substrings) that occur more than once in a DNA molecule.


// Example 1:

// Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
// Output: ["AAAAACCCCC","CCCCCAAAAA"]


// Example 2:

// Input: s = "AAAAAAAAAAAAA"
// Output: ["AAAAAAAAAA"]


// Constraints:

// 0 <= s.length <= 10^5
// s[i] is 'A', 'C', 'G', or 'T'.



#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_set<int> result_set;
        unordered_set<int> substrings;
        unordered_map<char, unsigned> charmap {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        for (int i = 0; i < int(s.size()) - 9; i++){
            int code = 0;
            for (size_t j = 0; j < 10; j++)
                code |= charmap[s[i + j]] << (2 * j);
            if (auto it = substrings.find(code); it != substrings.end()){
                if (auto it = result_set.find(code); it == result_set.end()){
                    result_set.insert(code);
                    result.push_back(s.substr(i, 10));
                }
            } else {
                substrings.insert(code);
            }
        }
        return result;
    }
};
