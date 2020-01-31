#include <stdio.h>
#include <stdlib.h>

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

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    if (nums1Size == 0 || nums2Size == 0)
        return NULL;

    int i = 0, j = 0;
    *returnSize = 0;

    qsortINT(nums1, 0, nums1Size - 1);
    qsortINT(nums2, 0, nums2Size - 1);
   
    int* returnNum = (int*)malloc(sizeof(int) * nums1Size);

    while(i < nums1Size && j < nums2Size){
        if (nums1[i] == nums2[j]){
            returnNum[(*returnSize)++] = nums1[i];
            ++i;
            ++j;
        }
        else if (nums1[i] < nums2[j])
            ++i;
        else
            ++j;        
    }    

    if (*returnSize < nums1Size)
        returnNum = (int*)realloc(returnNum, sizeof(int)**returnSize);
    
    return returnNum;
}

int main(void){
    int nums1[] = {1,2,2,1};
    int nums2[] = {1};

    int* result;
    int returnSize = 0;
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    
    result = intersect(nums1, nums1Size, nums2, nums2Size, &returnSize);

    int i = 0;
    for (; i < returnSize; ++i){
        printf("%d ", *(result + i));
    }
}