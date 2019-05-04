#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int cur = nums[0];
    int i = 1;
    int cnt = 1;
    for (i; i < numsSize; ++i) {
        if (cur == nums[i])
            ++cnt;
        else {
            --cnt;
            if (!cnt) {
                cur = nums[++i];
                cnt = 1;
            }
        }
    }
    return cur;
}

int main(void) {
    int num_arr[] = {2,2,1,1,1,2,2};

    printf("the majority element: %d", majorityElement(num_arr, sizeof(num_arr) / sizeof(int)));

    return 0;
}