#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    static char ret[201] = {0};
    strcpy(ret, strs[0]);
    for (int i = 1; i < strsSize; ++i)
    {
        for (int j = 0; j < strlen(ret); ++j)
        {
            //printf("%c %c\r\n", strs[i][j], ret[j]);
            if (strs[i][j] != ret[j])
            {
                ret[j]= '\0';
                break;
            }
        }
        if (!strlen(ret)) break;
    }

    return ret;
}

int main(void)
{
    char *str[] = {"ab", "a"};
    char *ret;

    ret = longestCommonPrefix(str, sizeof(str) / sizeof(char *));

    printf("ret: %s\r\n", ret);

    return 0;
}
