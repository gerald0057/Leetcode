#include <stdio.h>
#include <string.h>

void reverseString(char* s, int sSize)
{
    char *l = s, *r = s + sSize - 1;

    while (l < r)
    {
        char tmp = *l;
        *l = *r;
        *r = tmp;
        l++;r--;
    }
}

int main(void)
{
    char str[] = "Hello";

    printf("Original: %s\r\n", str);

    reverseString(str, strlen(str));

    printf("Current: %s\r\n", str);

    return 0;
}
