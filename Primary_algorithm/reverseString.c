#include <stdio.h>

void reverseString(char* s, int sSize) {
    int i = 0;
    char temp;
    for (; i < sSize / 2; ++i){
        temp = s[i];
        s[i] = s[sSize - 1 - i];
        s[sSize - 1 - i] = temp;
    }
}

int main(void){
    char str[] = {'h','e','l','l','o'};
    int sSize = sizeof(str) / sizeof(str[0]);

    reverseString(str, sSize);

    printf("%s\n", str);

    return 0;
}