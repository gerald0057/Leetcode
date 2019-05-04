#include <stdio.h>
#include <time.h>

int RemoveDuplicates(int* nums, const int numSize)
{
    if (numSize == 0) return 0;
    int i = 0, j = 0;
    for (; i < numSize; ++i)
    {
        if (nums[i] != nums[j])
            nums[++j] = nums[i];        
    }
    
    return ++j;
}

int main(void)
{
    clock_t start = clock();
    int nums[] = {0,0,1,1,1,2,2,3,3,4};

    int numSize = 0;
    numSize = sizeof(nums) / sizeof(nums[0]);

    int len = RemoveDuplicates(nums, numSize);
    int i = 0;
    for (; i < len; ++i)
    {
        printf("%d ", nums[i]);
    }

    printf("\ntime use: %lfms", (double)(clock() - start) / CLOCKS_PER_SEC);

    return 0;
}