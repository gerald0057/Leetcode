#include <stdio.h>
#include <stdlib.h>

#define __LOG(name, x) printf("\r\n%s: %d\r\n", name, x)

/**
 * @brief   要求：给定一个已按照升序排列的有序数组，找到两个数使得它们相加之和等于目标数。
 *          函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
 *          返回的下标值（index1 和 index2）不是从零开始的。你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 *          思路1：双指针，从两端向中间夹逼搜索
 * @param   numbers: 给定的有序数组
 * @param   numbersSize: 数组长度
 * @param   target: 目标的和值
 * @param   returnSize: 返回数组对的长度（2）
 * @retval  索引对
*/
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize){

  if (NULL == returnSize) {
    return NULL;
  }

  *returnSize  = 2;
  int *ret_index = (int *)malloc(sizeof(int) * (*returnSize));
  if (NULL == ret_index) {
    return NULL;
  }
  *(ret_index) = *(ret_index + 1) = -1;

  int left = 0, right = numbersSize - 1;

  while (left < right) {
    if (*(numbers + left) + *(numbers + right) < target) {
      ++left;
    } else if (*(numbers + left) + *(numbers + right) > target) {
      --right;
    } else {
      *(ret_index) = left + 1;
      *(ret_index + 1) = right + 1;
      break;
    }
  }

  return ret_index;
}

int main(void) {

  int nums[] = {2, 7, 11, 15};
  int num_size = sizeof(nums) / sizeof(nums[0]);
  int target = 9;
  int ret_size = 0;

  int *ret_index = twoSum(nums, num_size, target, &ret_size);
  printf("\r\nSum Pair Index:\r\n[");
  for (int i = 0; i < ret_size - 1; ++i) {
    printf("%d, ", *(ret_index + i));
  } printf("%d]\r\n", *(ret_index + ret_size - 1));

  free(ret_index);

  return 0;
}