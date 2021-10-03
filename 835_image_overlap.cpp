// ****************************************************************************
// 
// 835. Image Overlap
// https://leetcode.com/problems/image-overlap/
//
// ----------------------------------------------------------------------------


// Two images A and B are given, represented as binary, square matrices
// of the same size.  (A binary matrix has only 0s and 1s as values.)
// We translate one image however we choose (sliding it left, right, up, or
// down any number of units), and place it on top of the other image.
// After, the overlap of this translation is the number of positions
// that have a 1 in both images.

// (Note also that a translation does not include any kind of rotation.)

// What is the largest possible overlap?

// Example 1:
// Input: A = [[1,1,0],
//             [0,1,0],
//             [0,1,0]]
//        B = [[0,0,0],
//             [0,1,1],
//             [0,0,1]]
// Output: 3
// Explanation: We slide A to right by 1 unit and down by 1 unit.

// Notes:
// 1 <= A.length = A[0].length = B.length = B[0].length <= 30
// 0 <= A[i][j], B[i][j] <= 1



// ------------------------------------------------------------------------- //
// Slow (382ms)

#include <algorithm>
#include <utility>
#include <iostream>
#include <map>
#include <vector>

using std::vector;
using index2d = std::pair<int, int>;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<index2d> pivotsA;
        vector<index2d> pivotsB;
        size_t N = A.size();
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (A[i][j] == 1) pivotsA.emplace_back(i, j);
                if (B[i][j] == 1) pivotsB.emplace_back(i, j);
            }
        }
        int overlap = 0;
        std::map<index2d, int> tcounts;
        for (const auto p : pivotsA){
            for (const auto q : pivotsB){
                int offsetI = q.first - p.first;
                int offsetJ = q.second - p.second;
                tcounts[index2d(offsetI, offsetJ)] += 1;
            }
        }
        for (auto it : tcounts){
            overlap = std::max(overlap, it.second);
        }
        return overlap;
    }
};



// ------------------------------------------------------------------------- //
// Optimized (24ms)

#include <algorithm>
#include <array>

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2)
    {
        std::array<unsigned, 32> bits1 = imageToBits(img1);
        std::array<unsigned, 32> bits2 = imageToBits(img2);
        size_t N = img1.size();
        return std::max(maxConvolution(bits1, bits2, N),
                        maxConvolution(bits2, bits1, N));
        
    }
    
    int maxConvolution(std::array<unsigned, 32> img1,
                       std::array<unsigned, 32> img2,
                       size_t N = 32)
    {
        int max_overlap = 0;
        auto X = img1;
        for (int i = 0; i < N; i++) {
            auto Y = X;
            // Do left shifts
            for (int j = 0; j < N; j++) {
                max_overlap = std::max(max_overlap, convolve(Y, img2));
                shiftLeft(Y);
            }
            // Do right shifts
            Y = X;
            for (int j = 0; j < N; j++){
                max_overlap = std::max(max_overlap, convolve(Y, img2));
                shiftRight(Y);
            }
            shiftDown(X);
        }
        return max_overlap;
    }

    std::array<unsigned, 32> imageToBits(vector<vector<int>>& img)
    {
        std::array<unsigned, 32> result {0};
        int i = 0;
        for (const auto& row : img) {
            int j = 0;
            for (int b : row){
                result[i] |= b << (31 - j++);
            }
            i++;
        }
        return result;
    }

    inline int convolve(std::array<unsigned, 32> A, std::array<unsigned, 32> B)
    {
        int result = 0;
        for (int i = 0; i < 32; i++)
            result += countBits(A[i] & B[i]);
        return result;
    }

    inline int countBits(unsigned x)
    {
        int bits = 0;
        while (x) {
            bits++;
            x &= x - 1;
        }
        return bits;
    }

    inline void shiftLeft(std::array<unsigned, 32>& img)
    {
        for (int i = 0; i < 32; i++)
            img[i] = img[i] << 1;
    }

    inline void shiftRight(std::array<unsigned, 32>& img)
    {
        for (int i = 0; i < 32; i++)
            img[i] >>= 1;
    }

    inline void shiftDown(std::array<unsigned, 32>& img)
    {
        for (int i = 31; i > 0; i--)
            img[i] = img[i - 1];
        img[0] = 0;
    }

    void printImage(std::array<unsigned, 32>& img, int N = 32)
    {
        for (int i = 0; i < N; i++){
            for (int j = 31; j > 31 - N; j--)
                std::cout << (1 & (img[i] >> j)) << ' ';
            std::cout << '\n';
        }
        std::cout << '\n';
    }

};
