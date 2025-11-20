#include <stdio.h>
#include <stdlib.h>

char *rle(const char *raw)
{
    char *buffer = (char *)malloc(10240);
    if (NULL == buffer) return NULL;

    char *wr = buffer;
    int cnt = 1;
    // printf("input: %p %s\r\n", raw, raw);
    char last = *raw++;
    while (*raw)
    {
        // printf("-> %d %c %c\r\n", cnt, last, *raw);
        if (*raw != last)
        {
            // printf("raw:%p\r\n", raw);
            wr += sprintf(wr, "%d%c", cnt, last);
            // printf("last 1: %c %p\r\n", last, raw);
            last = (*raw);
            // printf("last 2: %c %p\r\n", last, raw);
            cnt = 1;
        }
        else
        {
            cnt++;
        }
        raw++;
    }

    wr += sprintf(wr, "%d%c", cnt, last);
    *wr = 0;

    return buffer;
}

char* countAndSay(int n)
{
    char *ret, *ret_val;
    if (n == 1) return "1";
    ret = countAndSay(n - 1);
    ret_val = rle(ret);
    if (ret && !(ret[0] == '1' && ret[1] == '\0')) free(ret);
    return ret_val;
}

int main(void)
{
    printf("cas:%s\r\n", countAndSay(25));

    return 0;
}