#include <stdio.h>

/**
 * @brief   要求：给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度
 *          思路1：快慢指针，快指针找到不用去除的元素，放到慢指针处，慢指针被动向前移动
 * @param   nums: 给定的数组
 * @param   numsSize: 数组长度
 * @param   val: 需要删除的值
 * @retval  数组删除部分元素后剩余的长度
*/
int removeElement(int *nums, int numsSize, int val) {

  if (NULL == nums || 0 >= numsSize) {
    return 0;
  }

  int slow = 0, fast = 0;
  while (fast < numsSize) {
    if (val != *(nums + fast)) {
      *(nums + slow++) = *(nums + fast++);
    } else {
      ++fast;
    }
  }

  return slow;
}

int main(void) {

  int nums[] = {3,2,2,3};
  int size = (int)(sizeof(nums) / sizeof(nums[0]));
  int del_val = 3;

  int new_size = removeElement(nums, size, del_val);
  printf("\r\nRemoved Array:\r\n[");
  for (int i = 0; i < new_size - 1; ++i) {
    printf("%d, ", nums[i]);
  } printf("%d]\r\n", nums[new_size - 1]);

  return 0;
}