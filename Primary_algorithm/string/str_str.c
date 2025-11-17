#include <stdio.h>

int strStr(char* haystack, char* needle) {
    char *pa = haystack, *pb = haystack;
    char *p = needle;

    while (*pa && *p)
    {
        if (*pb == *p)
        {
            pb++;
            p++;
        }
        else
        {
            pa++;
            pb = pa;
            p = needle;
        }
    }

    return *p ? -1 : (pa - haystack);
}

int main(void)
{
    char *haystack = "sadbutsad";
    char *needle = "btsad";

    int ret = strStr(haystack, needle);
    printf("strStr ret: %d\r\n", ret);

    return 0;
}