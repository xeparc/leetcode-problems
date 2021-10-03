#include "stdlib.h"
#include "string.h"
#include "stdio.h"

#define OFFSET ('A' - 'a')


char* next_word(char *s, int *length){
    // Skip whitespace
    while (*s == ' ') s++;
    int i = 0;
    for(; *(s + i) != 0 && *(s + i) != ' '; i++);
    *length = i > 0 ? i + 1 : 0;
    return s;
}


int is_vowel(char s){
    // Convert to lowercase
    if (s < 'a')
        s += OFFSET;
    return 
        s == 'a' || s == 'i' ||
        s == 'o' || s == 'u' || s == 'e';
}


char* to_goat_word(char *S, int length, char *dest, int index){
    char *dest_start = dest;
    if (*S == 0){
        *dest = 0;
        return dest;
    }
    if (is_vowel(S[0])){
        while (length--) *dest++ = *S++;
    } else {
        char first = *S++;
        while (--length) *dest++ = *S++;
        *dest++ = first;
    }
    *dest++ = 'm';
    *dest++ = 'a';
    while (index--) *dest++ = 'a';
    *dest = 0;
    return dest;
}


char * toGoatLatin(const char * S){
    int k = 0;
    int length = 0;
    size_t buffsize = 1;
    size_t current_buff_size = 10 * strlen(S) + 1;
    char* base = (char*)malloc(current_buff_size);
    size_t offset = 0;
    char* word = S;

    while (*word) {
        word = next_word(S, &length);
        printf("%s\n", word);
        if (length == 0) break;
        S += length;
        k++;
        buffsize += length + 2 + k;

        // if (buffsize > current_buff_size){
        //     base = (char*)realloc(base, buffsize);
        //     current_buff_size = buffsize;
        // }
        char* res = to_goat_word(word, length, base + offset, k);
        *res++ = ' ';
        offset += (res - (base + offset));
    }
    printf("\n%d\n", offset);
    base[offset--] = 0;
    base[offset] = 0;
    return base;
}


int main(){
    int i = 0;
    char *test = "Goat";
    char s[] = "Imo speak Goat Latin fd";
    char dest[90];
    // printf("%s", to_goat_word(test, 4, dest, 2));
    printf("%s", toGoatLatin(s));
    printf("%d", i);
    return 0;
}