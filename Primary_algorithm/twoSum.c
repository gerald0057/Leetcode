#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* twoSum(int* nums, int numsSize, int target) {
    int i = 0;
    int j = 0;
    int* ans = (int*)malloc(sizeof(int) * 2);

    for (; i< numsSize - 1; ++i)
        if (abs(nums[i]) <= abs(target))
            for (j = i + 1; j < numsSize; ++j)
                if (target - nums[i] == nums[j]){
                    ans[0] = i;
                    ans[1] = j;
                    return ans;
                }
}    


int main(void){
    int nums[] = {-1,-2,-3,-4,-5};
    int size = sizeof(nums) / sizeof(nums[0]);
    int target = -8;
    int* ans = NULL;
    
    ans = twoSum(nums, size, target);
    if (ans == NULL){
        printf("no answer");
        return 0;
    }

    int i = 0;
    for (; i < 2; ++i){
        printf("%d ", ans[i]);
    }

    return 0;
}