#include <stdio.h>

void swapINT(int* numA, int* numB){
    *numA += *numB;
    *numB = *numA - *numB;
    *numA = *numA - *numB;
}

void moveZeroes(int* nums, int numsSize) {
    int i = 0, j = 0;
    for (; i < numsSize - 1; ++i){
        if (nums[i] == 0){
            j = i + 1;
            while (nums[j] == 0 && j < numsSize - 1)
                ++j;
            swapINT(&nums[i], &nums[j]);
        }
    }
}

int main(void){
    int nums[] = {0};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    moveZeroes(nums, size);

    int i = 0;
    for (; i < size; ++i){
        printf("%d ", nums[i]);
    }

    return 0;
}