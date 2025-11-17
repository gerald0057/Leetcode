#include <stdio.h>

char *rle(const char *raw)
{
    static char buffer[1024];
    char *wr = buffer;
    int cnt = 1;
    printf("input: %p %s\r\n", raw, raw);
    char last = *raw++;
    while (*raw)
    {
        printf("-> %d %c %c\r\n", cnt, last, *raw);
        if (*raw != last)
        {
            printf("raw:%p\r\n", raw);
            wr += sprintf(wr, "%d%c", cnt, last);
            printf("last 1: %c %p\r\n", last, raw);
            last = (*raw);
            printf("last 2: %c %p\r\n", last, raw);
            cnt = 1;
        }
        else
        {
            cnt++;
        }
        raw++;
    }

    printf("+ %d %c\r\n", cnt, last);
    wr += sprintf(wr, "%d%c", cnt, last);
    *wr = 0;

    printf("ret: %s\r\n", buffer);

    return buffer;
}

char* countAndSay(int n)
{
    if (n == 1) return "1";
    return rle(countAndSay(n - 1));
}

int main(void)
{
    printf("cas:%s\r\n", countAndSay(4));

    return 0;
}
