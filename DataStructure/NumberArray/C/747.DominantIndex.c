#include <stdio.h>

/**
 * @brief   要求：在一个给定的数组nums中，总是存在一个最大元素 。
 *          查找数组中的最大元素是否至少是数组中每个其他数字的两倍。
 *          如果是，则返回最大元素的索引，否则返回-1。
 *          思路1：一次遍历，找到最大的两个数，判断是否满足2倍关系
 * @param   nums: 输入数组
 * @param   numsSize: 输入数组的长度
 * @retval  最大数索引
*/
int dominantIndex(int* nums, int numsSize) {

  int dominant_index = -1;

  /* null check */
  if (NULL == nums || 0 >= numsSize) {
    return dominant_index;
  }

  if (1 == numsSize) {
    dominant_index = 0;
    return dominant_index;
  }

  /* looking up */
  int index_1st = 0;
  int index_2nd = 0;
  for (int i = 1; i < numsSize; ++i) {

    /* start up modify */
    if (index_2nd == index_1st && *(nums + i) < *(nums + index_2nd)) {
      index_2nd = i;
    }

    /* find the greater num */
    if (*(nums + i) > *(nums + index_1st)) {
      index_2nd = index_1st;
      index_1st = i;

    } else if (*(nums + i) > *(nums + index_2nd)) {
      index_2nd = i;
    }
  }

  if (*(nums + index_1st) >= 2*(*(nums + index_2nd))) {
    dominant_index = index_1st;
  }

  return dominant_index;
}

int main(void) {

  int nums[] = {0, 0, 3, 1};
  int size = (sizeof(nums) / sizeof(nums[0]));

  printf("Dominant Index: \t%d.\r\n", dominantIndex(nums, size));

  return 0;
}