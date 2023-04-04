// ****************************************************************************
// 
// 2405. Optimal Partition of String
// https://leetcode.com/problems/optimal-partition-of-string/description/
//
// ----------------------------------------------------------------------------
//
//
//  Given a string s, partition the string into one or more substrings such
//  that the characters in each substring are unique. That is, no letter
//  appears in a single substring more than once.
//  Return the minimum number of substrings in such a partition.
//  Note that each character should belong to exactly one substring in a partition.
//  
//  
//  Example 1:
//  Input: s = "abacaba"
//  Output: 4
//  Explanation:
//  Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
//  It can be shown that 4 is the minimum number of substrings needed.
//  
//  Example 2:
//  Input: s = "ssssss"
//  Output: 6
//  Explanation:
//  The only valid partition is ("s","s","s","s","s","s").
//  
//  Constraints:
//      * 1 <= s.length <= 10^5
//      * s consists of only English lowercase letters.



#include <string>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> chars;
        int partitions = 0;
        for (char c : s){
            if (chars.count(c)){
                chars.clear();
                partitions++;
            }
            chars.insert(c);
        }
        partitions += chars.empty() ? 0 : 1;
        return partitions;
    }
};
