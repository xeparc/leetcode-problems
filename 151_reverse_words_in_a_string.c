// ///////////////////////////////////////////////////////////////////////////
//
// 151. Reverse Words in a String
// https://leetcode.com/problems/reverse-words-in-a-string/
//
// ***************************************************************************
//
//
// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters.
// The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces
// between two words. The returned string should only have a single space
// separating the words. Do not include any extra spaces.
//
//
// Example 1:
// Input: s = "the sky is blue"
// Output: "blue is sky the"
//
// Example 2:
// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
//
// Example 3:
// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words
// to a single space in the reversed string.
//
// Example 4:
// Input: s = "  Bob    Loves  Alice   "
// Output: "Alice Loves Bob"
//
// Example 5:
// Input: s = "Alice does not even like bob"
// Output: "bob like even not does Alice"
//
//
// Constraints:
// * 1 <= s.length <= 10^4
// * s contains English letters (upper-case and lower-case), digits, and spaces ' '.
// * There is at least one word in s.



#include "stdlib.h"

/*  ----------------------
    First written solution
*/
// char * reverseWords(char * s){
//     // skip leading white space
//     while (*s == ' ')
//         s++;
//     int N = 0;
//     int i = 0;
//     int whitespaces = 0;
//     int characters = 0;
//     while(s[i]){
//         if (s[i] == ' '){
//             whitespaces++;
//             int n = 0;
//             while (s[i] == ' ')
//                 i++, n++;
//             if (s[i] == 0)
//                 whitespaces--;
//             else
//                 N += n;
//         }
//         else{
//             N++;
//             characters++;
//             i++;
//         }
//     }
//     char *result = (char*)malloc((characters + whitespaces + 1) * sizeof(char));
//     N--;
//     int k = 0;
//     while (N >= 0){
//         int j = N;
//         for (; j >= 0 && s[j] != ' '; j--);
//         strncpy(result + k, s + j + 1, N - j);
//         k += N - j;
//         while(j >= 0 && s[j] == ' ')
//             j--;
//         N = j;
//         if (j >= 0)
//             result[k++] = ' ';
//     }
//     result[whitespaces + characters] = 0;
//     return result;
// }


void reverse(char *begin, char *end)
{
    while (begin < end){
        char c = *begin;
        *begin = *end;
        *end = c;
        begin++, end--;
    }
}

char * reverseWords(char * s){
    // Reverse whole string
    int N = strlen(s);
    reverse(s, s + N - 1);
    // Reverse words
    for (int i = 0; i < N;){
        while (s[i] == ' ') i++;
        // i points at the first non-whitespace character or end of string
        if (i < N){
            int j = i;
            while (j < N && s[j] != ' ') j++;
            // j points at the first whitespace character or end of string
            reverse(s + i, s + j - 1);
            i = j;
        }
    }
    int k = 0;
    int i = 0;
    // Clear leading whitespaces
    while (s[i] == ' ') i++;
    // Clear excess whitespaces between words
    while (i < N){
        if (s[i] == ' '){
            while (i < N && s[i] == ' ') i++;
            if (i < N) s[k++] = ' ';
        }
        else
            s[k++] = s[i++];
    }
    s[k] = 0;
    return s;
}
