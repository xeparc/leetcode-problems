// ****************************************************************************
// 
// 412. Fizz Buzz
// https://leetcode.com/problems/fizz-buzz/
//
// ----------------------------------------------------------------------------

// Write a program that outputs the string representation of numbers from 1 to n.

// But for multiples of three it should output “Fizz” instead of the number
// and for the multiples of five output “Buzz”. For numbers which are
// multiples of both three and five output “FizzBuzz”.

// Example:
// n = 15,
// Return:
// [
//     "1",
//     "2",
//     "Fizz",
//     "4",
//     "Buzz",
//     "Fizz",
//     "7",
//     "8",
//     "Fizz",
//     "Buzz",
//     "11",
//     "Fizz",
//     "13",
//     "14",
//     "FizzBuzz"
// ]

#include "stdlib.h"
#include "string.h"
#include "stdio.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    int size = n * 11;
    *returnSize = n;
    char* buffer = (char*)malloc(size);
    char** pointers = (char**)malloc(n * sizeof(char*));
    for (size_t i = 0; i < n; i++)
        pointers[i] = buffer + i * 11;

    char current[11];
    for (int k = 0, i = 1; i <= n; i++, k++){
        memset(current, 0, 11);
        int m3 = i % 3;
        int m5 = i % 5;
        if (m3 && m5){
            _itoa(i, current, 10);
        } else{
            if (!m3) strcpy(current, "Fizz");
            if (!m5) strcat(current, "Buzz");
        }
        strcpy(pointers[k], current);
    }
    return pointers;
}

int main(){
    int n;
    scanf("%d", &n);
    int size;
    char **res = fizzBuzz(n, &size);
    for(int i = 0; i < size; i++){
        printf("%s\n", res[i]);
    }
    return 0;
}