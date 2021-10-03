// ****************************************************************************
// 
// 39. Combination Sum
// https://leetcode.com/problems/combination-sum/
// 
// ----------------------------------------------------------------------------


// Given an array of distinct integers candidates and a target integer target,
// return a list of all unique combinations of candidates where the chosen
// numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times.
// Two combinations are unique if the frequency of at least one of the
// chosen numbers is different.

// It is guaranteed that the number of unique combinations that sum up to
// target is less than 150 combinations for the given input.


// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.


// Example 2:

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]


// Example 3:

// Input: candidates = [2], target = 1
// Output: []


// Example 4:

// Input: candidates = [1], target = 1
// Output: [[1]]


// Example 5:

// Input: candidates = [1], target = 2
// Output: [[1,1]]


// Constraints:

// 1 <= candidates.length <= 30
// 1 <= candidates[i] <= 200
// All elements of candidates are distinct.
// 1 <= target <= 500



#include <algorithm>
#include <vector>

using namespace std;

// Slow (100ms)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return combinationAux(candidates.begin(), candidates.end(), target);
    }
    
    vector<vector<int>> combinationAux(
        vector<int>::const_iterator begin,
        vector<int>::const_iterator end,
        int target)
    {
        if (begin == end)
            return {};
        int num = 0;
        vector<vector<int>> result;
        vector<int> x;
        while (num < target){
            for (auto& v : combinationAux(begin + 1, end, target - num)){
                for (int i : x)
                    v.push_back(i);
                result.push_back(v);
            }
            x.push_back(*begin);
            num += *begin;
        }
        if (num == target){
            result.push_back(x);
        }
        return result;
    }
};


// Optimized (8ms)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates.begin(), candidates.end(), target, 0);
        return solutions;
    }

    void dfs(vector<int>::const_iterator beg,
             vector<int>::const_iterator end,
             int target,
             int accum)
    {
        for (auto it = beg; it < end; ++it){
            int c = *it;
            if (accum + c == target){
                m_path.push_back(c);
                solutions.push_back(m_path);
                m_path.pop_back();
            }
            else if (accum + c < target){
                m_path.push_back(c);
                dfs(it, end, target, accum + c);
                m_path.pop_back();
            }
            else {
                break;
            }
        }
    }
    
private:
    vector<int> m_path {};
    vector<vector<int>> solutions {};
};
