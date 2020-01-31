#include <stdio.h>

void swapINT(int* numA, int* numB){
    *numA += *numB;
    *numB = *numA - *numB;
    *numA = *numA - *numB;
}

void reverse(int* nums, int pos_former, int pos_latter){
    for (; pos_former < pos_latter; ++pos_former, --pos_latter){
        swapINT(nums + pos_former, nums + pos_latter);
    }
}

void rotate(int* nums, const int numsSize, int k){
    k %= numsSize;

    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

int main(void){
    int nums[] = {4,1,2,1,2};
    int size = sizeof(nums) / sizeof(nums[0]);

    rotate(nums, size, 3);

    int i = 0;
    for (; i < size; ++i){
        printf("%d ", nums[i]);
    }

    return 0;
}