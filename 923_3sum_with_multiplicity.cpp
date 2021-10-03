// ///////////////////////////////////////////////////////////////////////////
//
// 923. 3Sum With Multiplicity
// https://leetcode.com/problems/3sum-with-multiplicity/
//
// ***************************************************************************
//
//
// Given an integer array arr, and an integer target, return the number
// of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.
// As the answer can be very large, return it modulo 10^9 + 7.
//
//
// Example 1:
//
// Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
// Output: 20
// Explanation:
// Enumerating by the values (arr[i], arr[j], arr[k]):
// (1, 2, 5) occurs 8 times;
// (1, 3, 4) occurs 8 times;
// (2, 2, 4) occurs 2 times;
// (2, 3, 3) occurs 2 times.
//
// Example 2:
//
// Input: arr = [1,1,2,2,2,2], target = 5
// Output: 12
// Explanation:
// arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
// We choose one 1 from [1,1] in 2 ways,
// and two 2s from [2,2,2,2] in 6 ways.
//
// Constraints:
//
// 3 <= arr.length <= 3000
// 0 <= arr[i] <= 100
// 0 <= target <= 300



#include <map>
#include <vector>

using namespace std;

class Solution {
public:

    int threeSumMulti(vector<int>& arr, int target) {
        constexpr long N = 1'000'000'007;
        long two_sums[301] = {0};
        long answer = 0;
        two_sums[arr[0] + arr[1]] = 1;
        for (size_t i = 2; i < arr.size(); i++){
            int T = target - arr[i];
            if (T >= 0)
                answer = (answer + two_sums[T]) % N;
            for (size_t j = 0; j < i; j++)
                two_sums[arr[j] + arr[i]]++;
        }
        return answer;
    }

    int threeSumMultiSlow(vector<int>& arr, int target) {
        constexpr long N = 1'000'000'007;
        long answer = 0;
        std::map<int, long> two_sums;
        two_sums[arr[0] + arr[1]] = 1;
        for (size_t i = 2; i < arr.size(); i++){
            auto it = two_sums.find(target - arr[i]);
            if (it != two_sums.end()){
                long w = it->second;
                answer = (answer + w) % N;
            }
            for (size_t j = 0; j < i; j++){
                two_sums[arr[j] + arr[i]]++;
            }
        }
        return answer;
    }

    int threeSumMultiDumb(vector<int> arr){
        constexpr long N = 1'000'000'007;
        vector<int> U;
        vector<int> counts;
        int last = -1;
        for (int x : arr){
            if (x == last)
                ++counts.back();
            else{
                last = x;
                U.push_back(x);
                counts.push_back(1);
            }
        }
        for (size_t i = 0; i < U.size(); i++){
            long c = counts[i];

            // Case 1: (x, y, z) such that arr[x] == arr[y] == arr[z]
            // Number of tuples (x, y, z) such that
            // arr[x] == arr[y] == arr[z] == U[i]
            // Note: If c < 3, n == 0
            if (3 * U[i] == target && c > 2){
                long n = (c * (c - 1) * (c - 2) / 6) % N;
                answer = (answer + n) % N;
            }

            // Case 2: (x, y, z) such that arr[x] != arr[y] != arr[z]
            for (size_t j = i + 1; j < U.size() - 1; j++){
                for (size_t k = j + 1; k < U.size(); k++){
                    if (U[j] + U[k] == target - U[i])
                        answer = (answer + c * counts[j] * counts[k]) % N;
                }
            }

            // Case 3: (x, y, z) such that arr[y] == arr[z]
            // and arr[x] != arr[y], arr[x] != arr[z]
            for (size_t j = i + 1; j < U.size(); j++){
                if (counts[j] >= 2 && (U[i] + 2 * U[j] == target)){
                    long n = counts[j] * (counts[j] - 1) / 2;
                    answer = (answer + counts[i] * n) % N;
                }
                if (counts[i] >= 2 && (2 * U[i] + U[j] == target)){
                    long n = counts[i] * (counts[i] - 1) / 2;
                    answer = (answer + n * counts[j]) % N;
                }
            }
        }
        return answer;
    }

    // Credits to DBabichev
    int threeSumMultiFast(vector<int>& arr, int target) {
        constexpr long N = 1'000'000'007;
        std::map<int, long> counts;
        for (int x : arr)
            counts[x]++;

        long answer = 0;
        // Case 1:
        // arr[i] != arr[j] != arr[k]
        for (auto i = counts.begin(); i != counts.end(); i++){
            for (auto j = counts.begin(); j != counts.end(); j++){
                if (i == j) continue;
                const auto [a, ca] = *i;
                const auto [b, cb] = *j;
                if (a < b && b < target - a - b)
                    answer = (answer + ca * cb * counts[target - a - b]) % N;
            }
        }
        for (auto i = counts.begin(); i != counts.end(); i++){
            const auto [x, c] = *i;
            // Case 2:
            // arr[i] == arr[j] == arr[k]
            if (3 * x == target)
                answer = (answer + c * (c - 1) * (c - 2) / 6) % N;
            // Case 3:
            // arr[i] == arr[j], arr[i] != arr[k]
            else
                answer = (answer + c * (c - 1) * counts[target - 2 * x] / 2) % N;
        }
        return answer;
    }
};
