#include <stdio.h>

/**
 * @brief   要求：给定一个二进制数组， 计算其中最大连续1的个数。
 *          思路1：计数，加一个最大值寄存器，比较
 * @param   nums: 给定的数组
 * @param   numsSize: 数组长度
 * @retval  最大连续1的个数
*/
int findMaxConsecutiveOnes(int *nums, int numsSize){

  if (NULL == nums || 0 >= numsSize) {
    return 0;
  }

  int max_cnt = 0;
  int cnt = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (*(nums + i)) { ++cnt; }
    else {
      max_cnt = max_cnt > cnt ? max_cnt : cnt;
      cnt = 0;
    }
  }

  return (max_cnt > cnt ? max_cnt : cnt);
}

int main(void) {

  int nums[] = {1,1,0,1,1,1};
  int size = (int)(sizeof(nums) / sizeof(nums[0]));

  printf("\r\nMax Consecutive Ones:\r\n%d\r\n", findMaxConsecutiveOnes(nums, size));

  return 0;
}