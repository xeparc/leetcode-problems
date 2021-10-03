// ****************************************************************************
// 
// 220. Contains Duplicate III
// https://leetcode.com/problems/contains-duplicate-iii/
//
// ----------------------------------------------------------------------------


// Given an array of integers, find out whether there are two distinct
// indices i and j in the array such that the absolute difference between
// nums[i] and nums[j] is at most t and the absolute difference
// between i and j is at most k.

// Example 1:
// Input: nums = [1,2,3,1], k = 3, t = 0
// Output: true

// Example 2:
// Input: nums = [1,0,1,1], k = 1, t = 2
// Output: true

// Example 3:
// Input: nums = [1,5,9,1,5,9], k = 2, t = 3
// Output: false


#include <algorithm>
#include <deque>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k < 0 or t < 0) return false;
        k++;
        size_t N = nums.size();
        std::multiset<int> kset(nums.begin(), nums.begin() + std::min(N, (size_t)k));
        auto it = kset.begin();
        auto it2 = it;
        while (it != kset.end()){
            it2 = std::next(it);
            if (it2 == kset.end())
                break;
            if (abs(static_cast<long int>(*it2) - static_cast<long int>(*it)) <= t)
                return true;
            it = it2;
        }
        
        std::deque<int> kqueue(nums.begin(), nums.begin() + std::min(N, (size_t)k));
        for (size_t i = k; i < N; i++){
            kset.erase(kset.find(kqueue.front()));
            kqueue.pop_front();
            int key = nums[i];
            auto hi = kset.lower_bound(key);
            if (hi != kset.end() and abs(static_cast<long int>(*hi) - static_cast<long int>(key)) <= t)
                return true;
            if (hi != kset.begin()){
                auto lo = --hi;
                if (lo != kset.end() and abs(static_cast<long int>(*lo) - static_cast<long int>(key)) <= t)
                    return true;
            }
            kset.insert(key);
            kqueue.push_back(key);
        }
        return false;
    }
};


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k < 0 or t < 0) return false;
        std::multiset<int> kset;
        for (size_t i = 0; i < nums.size(); i++){
            if (i > k)
                kset.erase(kset.find(nums[i - k - 1]));
            int key = nums[i];
            auto hi = kset.lower_bound(key);
            if (hi != kset.end() and abs(static_cast<long int>(*hi) - static_cast<long int>(key)) <= t)
                return true;
            if (hi != kset.begin()){
                auto lo = --hi;
                if (lo != kset.end() and abs(static_cast<long int>(*lo) - static_cast<long int>(key)) <= t)
                    return true;
            }
            kset.insert(key);
        }
        return false;
    }
};
