#include <stdio.h>

int singleNumber(int* num, int numsSizes)
{
    int i = 1;
    int result = num[0];
    for (; i < numsSizes; ++i)
    {
        result ^= num[i];
    }

    return result;
}

int main(void)
{
    int nums[] = {4,1,2,1,2};
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("%d", singleNumber(nums, size));

    return 0;
}