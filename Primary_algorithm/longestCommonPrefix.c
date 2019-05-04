#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {    
    char* retChar = NULL;
    if (strsSize == 0){
        if (NULL == (retChar = (char*)malloc(sizeof(char) * 2))){
            perror("malloc error");
            exit(3);
        }
        *(retChar) = '\0';
        return retChar;
    }
    unsigned int len = strlen(*strs);
    if (len == 0){
        if (NULL == (retChar = (char*)malloc(sizeof(char) * 2))){
            perror("malloc error");
            exit(2);
        }
        *(retChar) = '\0';
        return retChar;
    }    
    if (NULL == (retChar = (char*)malloc(sizeof(char) * (len + 1))) && len != 0){
        perror("malloc error");
        exit(1);
    }
    
    strcpy(retChar, *strs);

    int i = 1, j = 0;
    for (; i < strsSize; ++i)
        for (j = 0; *(retChar + j) != '\0'; ++j)
            if (*(*(strs + i) + j) != *(retChar + j)){
                *(retChar + j) = '\0';
                break;
            }

    return retChar;
}

int main(void){
    char* strs[] = {"fo","flow","flight"};
    int strsSize = sizeof(strs) / sizeof(strs[0]);

    printf("%s", longestCommonPrefix(strs, strsSize));

    return 0;
}