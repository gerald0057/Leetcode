#include <stdio.h>

int firstUniqChar(char* s) {
    int abc_index[26] = {0};

    int i = 0;
    for (; s[i] != '\0'; ++i)
        ++abc_index[s[i] - 97];

    for (i = 0; s[i] != '\0'; ++i)
        if (abc_index[s[i] - 97] == 1)
            return i;

    return -1;
}

int main(void){
    char str[] = {"lleett"};

    printf("%d", firstUniqChar(str));
    // printf("%d", 'A' - 0);

    return 0;
}