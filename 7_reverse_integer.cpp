// ****************************************************************************
// 
// 7. Reverse Integer
// https://leetcode.com/problems/reverse-integer/
//
// ----------------------------------------------------------------------------
//
//
// Given a signed 32-bit integer x, return x with its digits reversed.
// If reversing x causes the value to go outside the signed 32-bit
// integer range [-231, 231 - 1], then return 0.
// Assume the environment does not allow you to store 64-bit integers
// (signed or unsigned).



class Solution {
public:
    __attribute__((no_sanitize("undefined")))
    int reverse(int x) {
        int reversed = 0;
        int sign = x >= 0 ? 1 : -1;
        if (x < 0)
            x = -x;
        for (int i = 0; (i < 10) && (x > 0); i++){
            int r = reversed * 10 + x % 10;
            x = x / 10;
            if (r / 10 != reversed)
                return 0;
            reversed = r;
        }
        return sign * reversed;
    }
};
