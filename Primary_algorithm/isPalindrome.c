#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isPalindrome(char* s) {
    int len = 0;
    int rellen = 0;
    if (0 == (len = strlen(s)))
        return true;

    int i = 0;
    int* abc_index = (int*)malloc(sizeof(int) * len);
    memset(abc_index, 0, sizeof(int) * len);
    for (; i < len; ++i){
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            if (s[i] > 'Z')
                abc_index[rellen] = s[i] - 32 - '0';
            else if (s[i] < 'A')
                abc_index[rellen] = s[i] - '0';
            else
                abc_index[rellen] = s[i] - '0';
            
            ++rellen;
        }
    }
    abc_index = (int*)realloc(abc_index, sizeof(int) * rellen);

    for (i = 0; i < rellen / 2; ++i)
        if (abc_index[i] != abc_index[rellen - 1 - i])
            return false;

    return true;
}

int main(void){
    char str[] = {"0P0"};

    printf("%s", isPalindrome(str) == true ? "true" : "false");

    return 0;
}