#include <stdio.h>

void qsortINT(int* nums, int pos_former, int pos_latter){
    if(pos_former < pos_latter)
    {
        int i = pos_former, j = pos_latter, x = nums[pos_former];
        while(i < j){
            while(i < j && nums[j] >= x)
                --j;
            if(i < j)
                nums[i++] = nums[j];
            
            while(i < j && nums[i] <= x)
                ++i;
            if(i < j)
                nums[j--] = nums[i];            
        }
        
        nums[i]=x;
        qsortINT(nums, pos_former, i-1);
        qsortINT(nums, i+1, pos_latter);        
    }
}

int containDuplicates(int* nums, int numsSize){
    qsortINT(nums, 0, numsSize - 1);

    int i = 0;
    for (; i < numsSize - 1; ++i){
        if (nums[i] == nums[i + 1])
            return 1;
    }

    return 0;
}

int main(void){
    int nums[] = {1,2,3,4};
    int numsSizes = sizeof(nums) / sizeof(nums[0]);

    if (containDuplicates(nums, numsSizes))
        printf("True");
    else
        printf("False");

    return 0;
}