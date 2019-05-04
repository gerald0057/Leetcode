#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    int len_hay = strlen(haystack), len_ned = strlen(needle);
    if (len_hay < len_ned)
        return -1;
    if (len_ned == 0)
        return 0;

    int i = 0, j = 0;
    unsigned char flag = 0;
    for (; i < len_hay; ++i){
        flag = 0;
        if ((i + len_ned <= len_hay) && haystack[i] == needle[0] && haystack[i + len_ned - 1] == needle[len_ned - 1]){
            for (j = i + 1; j < i + len_ned - 1; ++j){
                if (haystack[j] != needle[j - i]){
                    flag = 1;
                    break;
                }                    
            }
            if (!flag)
                return i;
        }
    }

    return -1;  
}

int main(void){
    char haystack[] = {"babba"};
    char needle[] = {"bbb"};

    printf("%d", strStr(haystack, needle));

    return 0;
}

