#include <stdio.h>

int minSubArrayLen(int s, int *nums, int numsSize){

  if (NULL == nums || 0 >= numsSize) {
    return 0;
  }

  int min_len = numsSize;
  
  

  return min_len;
}

int main(void) {

  int sub_sum = 7;
  int nums[] = {2, 3, 1, 2, 4, 3};
  int size = (int)(sizeof(nums) / sizeof(nums[0]));

  printf("\r\nMinimum Sub-Array Length:\r\n%d\r\n", minSubArrayLen(sub_sum, nums, size));

  return 0;
}