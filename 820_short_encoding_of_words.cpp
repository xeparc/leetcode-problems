// ///////////////////////////////////////////////////////////////////////////
//
// 820. Short Encoding of Words
// https://leetcode.com/problems/short-encoding-of-words/
//
// ***************************************************************************
//
//
// A valid encoding of an array of words is any reference string s and
// array of indices indices such that:
//         words.length == indices.length
// The reference string s ends with the '#' character.
// For each index indices[i], the substring of s starting from indices[i]
// and up to (but not including) the next '#' character is equal to words[i].
// Given an array of words, return the length of the shortest reference
// string s possible of any valid encoding of words.
// 
// 
// Example 1:
// Input: words = ["time", "me", "bell"]
// Output: 10
// Explanation: A valid encoding would be s = "time#bell#" and indices = [0, 2, 5].
// words[0] = "time", the substring of s starting from indices[0] = 0
// to the next '#' is underlined in "time#bell#"
// words[1] = "me", the substring of s starting from indices[1] = 2
// to the next '#' is underlined in "time#bell#"
// words[2] = "bell", the substring of s starting from indices[2] = 5
// to the next '#' is underlined in "time#bell#"
// 
// 
// Example 2:
// Input: words = ["t"]
// Output: 2
// Explanation: A valid encoding would be s = "t#" and indices = [0].



#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool sortkey(const string&, const string&);


class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        std::sort(words.begin(), words.end(), sortkey);
        vector<string>::iterator lastword = words.begin();
        // std::vector<string> encoding {*lastword};
        int length = lastword->size() + 1;
        for (int i = 1; i < words.size(); i++, lastword++){
            auto n = lastword->rfind(words[i]);
            // Case 1: Not a suffix, add to encoding
            if (n == string::npos || (n + words[i].size() != lastword->size())){
                // encoding.push_back("#");
                // encoding.push_back(words[i]);
                length += 1 + words[i].size();
            }
            // Case 2: Suffix, already in encoding
            else {}
        }
        // encoding.push_back("#");
        return length;
    }
};

bool sortkey(const string& a, const string& b){
    string::const_reverse_iterator ita = a.rbegin();
    string::const_reverse_iterator itb = b.rbegin();
    for (; ita != a.rend() && itb != b.rend(); ita++, itb++){
        if (*ita < *itb)
            return true;
        if (*ita > *itb)
            return false;
    }
    if (ita != a.rend() && itb == b.rend())
        return true;
    return false;
}
