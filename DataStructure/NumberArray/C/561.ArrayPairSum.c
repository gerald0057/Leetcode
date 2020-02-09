#include <stdio.h>

#define __LOG(name, x) printf("\r\n%s: %d\r\n", name, x)

/**
 * @brief   要求：给定长度为 2n 的数组, 你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到 n 的 min(ai, bi) 总和最大
 *          n 是正整数,范围在 [1, 10000]. 数组中的元素范围在 [-10000, 10000].
 *          思路1：排序，由于界定了范围，使用基数排序降低时间复杂度
 * @param   nums: 给定的数组
 * @param   numsSize: 数组长度
 * @retval  min数对的最大和
*/
int arrayPairSum(int *nums, int numsSize){

  int ret_sum = 0;

  if (NULL == nums || 0 >= numsSize) {
    return ret_sum;
  }

  int Base[20001] = {0};
  for (int i = 0; i < numsSize; ++i) {
    ++Base[*(nums + i) + 10000];
  }

  int min_index = 0;
  for (int i = 0; i < 20001;) {
    
    if (0 != Base[i]) {

      if (!(min_index % 2)) { ret_sum += i - 10000; }
      ++min_index;
      --Base[i];

    } else { ++i; }
  }

  return ret_sum;
}

int main(void) {

  int nums[] = {};
  int size = (int)(sizeof(nums) / sizeof(nums[0]));

  printf("\r\nMax Pari Sum:\r\n%d\r\n", arrayPairSum(nums, size));

  return 0;
}