// ///////////////////////////////////////////////////////////////////////////
//
// 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
//
// ***************************************************************************
//
//
// You are given an array of integers arr and an integer target.
// You have to find two non-overlapping sub-arrays of arr each with
// a sum equal target. There can be multiple answers so you have to
// find an answer where the sum of the lengths of the two sub-arrays is minimum.
// Return the minimum sum of the lengths of the two required sub-arrays,
// or return -1 if you cannot find such two sub-arrays.
//
//
// Example 1:
// Input: arr = [3,2,2,4,3], target = 3
// Output: 2
// Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). The sum of
// their lengths is 2.
//
// Example 2:
// Input: arr = [7,3,4,7], target = 7
// Output: 2
// Explanation: Although we have three non-overlapping sub-arrays of sum = 7
// ([7], [3,4] and [7]), but we will choose the first and third sub-arrays
// as the sum of their lengths is 2.
//
// Example 3:
// Input: arr = [4,3,2,6,2,3,4], target = 6
// Output: -1
// Explanation: We have only one sub-array of sum = 6.
//
//
// Constraints:
// 1 <= arr.length <= 10^5
// 1 <= arr[i] <= 1000
// 1 <= target <= 10^8



#include <algorithm>
#include <deque>
#include <utility>
#include <vector>

using Interval = std::pair<int, int>;
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        std::deque<int> Q;
        int cumsum = 0;
        // `subarrays` contains the start, end indices
        // of sub-arrays with sum == `target`
        std::vector<Interval> subarrays;
        for (int i = 0; i < arr.size(); i++){
            Q.push_back(arr[i]);
            cumsum += arr[i];
            while (!Q.empty() && cumsum > target){
                cumsum -= Q.front();
                Q.pop_front();
            }
            if (cumsum == target){
                int end = i + 1;
                int start = i - Q.size() + 1;
                subarrays.push_back(Interval(start, end));
            }
        }
        if (subarrays.size() < 2)
            return -1;
        // `shortest_left[i]` is the length of the shortest
        // sub-array with endpoint <= i. `endpoints` is array
        // containing the right indices of all sub-arrays with
        // sum == `target`
        std::vector<int> shortest_left;
        std::vector<int> endpoints;
        int current_shortest = -1 ^ (1 << (8 * sizeof(int) - 1));
        for (int i = 0; i < subarrays.size(); i++){
            int start = subarrays[i].first;
            int end = subarrays[i].second;
            current_shortest = std::min(end - start, current_shortest);
            shortest_left.push_back(current_shortest);
            endpoints.push_back(end);
        }
        int result = INT_MAX;
        // for (int i = 0; i < subarrays.size(); i++){
        //     cout << '[' << subarrays[i].first << ", " << subarrays[i].second << "] ";
        // }
        // Dynamic programing //
        // For each sub-array, search it's left
        // index in `endpoints`. Let it be `j`. Then the shortest
        // non-overlapping sub-array size is `shortest_left[j]`
        for (int i = 1; i < subarrays.size(); i++){
            int ylen = subarrays[i].second - subarrays[i].first;
            int start = subarrays[i].first;
            auto it = std::lower_bound(endpoints.begin(), endpoints.end(), start);
            if (*it > start) it--;
            if (it < endpoints.begin())
                continue;
            int j = std::distance(endpoints.begin(), it);
            int xlen = shortest_left[j];
            result = std::min(result, xlen + ylen);
        }
        return result == INT_MAX ? -1 : result;
    }

    // Refactored solution
    int minSumOfLengths_simple(vector<int>& arr, int target) {
        // Dynamic programming - do prefix scan of `arr` //
        // `left[i]` contains the length of the shortest
        // sub-array that ends at index <= `i`.
        std::vector<int> left = scan(arr.begin(), arr.end(), target);
        // Now do suffix scan of `arr`
        // `right[i]` contains the length of the shortest
        // sub-array that starts at index >= `i`. The
        // array `right` is reversed!
        std::vector<int> right = scan(arr.rbegin(), arr.rend(), target);
        int result = INT_MAX;
        // `*a` is the length of the shortest
        // sub-array in range [i, N]
        // `*b` is the length of the shortest
        // sub-array in range [0, i)
        auto a = right.rbegin() + 1;
        auto b = left.begin();
        for (; a != right.rend(); a++, b++){
            if (*a == INT_MAX || *b == INT_MAX)
                continue;
            result = std::min(result, *a + *b);
        }
        return result == INT_MAX ? -1 : result;
    }

    template <typename It>
    std::vector<int> scan(It begin, It end, int target)
    {
        std::deque<int> Q;
        std::vector<int> prefix;
        int shortest = INT_MAX;
        int cumsum = 0;
        for (auto it = begin; it != end; it++){
            cumsum += *it;
            Q.push_back(*it);
            while (!Q.empty() && cumsum > target){
                cumsum -= Q.front();
                Q.pop_front();
            }
            if (cumsum == target)
                shortest = std::min(shortest, static_cast<int>(Q.size()));
            prefix.push_back(shortest);
        }
        return prefix;
    }
};
