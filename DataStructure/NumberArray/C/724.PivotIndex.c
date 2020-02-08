#include <stdio.h>

/**
 * @brief   要求：给定一个整数类型的数组 nums，请编写一个能够返回数组“中心索引”的方法。
 *          我们是这样定义数组中心索引的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。
 *          如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。
 *          思路1：建立两个指针分别指向数组头尾，向中间扫描，比较扫描过的累计和的大小，只有累计和小的一端能够向中间扫描，然后进行循环中止的判断
 *          思路1错误：未考虑负数情况
 *          思路2：一次遍历求出总和，二次遍历找到一半位置
 * @param   nums: 输入数组
 * @param   numsSize: 输入数组的长度
 * @retval  中心索引
*/
int pivotIndex_1_Error(int *nums, int numsSize) {
  
  int pivot_index = -1;

  /* null check */
  if (NULL == nums || 0 >= numsSize) {
    return pivot_index;
  }

  int index_head = 0, index_tail = numsSize - 1;
  int sum_head = 0, sum_tail = 0;

  /* get the sum */
  sum_head += *(nums + index_head);
  sum_tail += *(nums + index_tail);

  /* start */
  while (index_head + 2 < index_tail) {

    if (sum_tail <= sum_head) {
      --index_tail;
      sum_tail += *(nums + index_tail);
    } else {
      ++index_head;
      sum_head += *(nums + index_head);
    }
  }

  if (sum_head == sum_tail) {
    pivot_index = index_head + 1;
  }

  return pivot_index;
}

int pivotIndex_2_Success(int *nums, int numsSize) {

  int pivot_index = -1;

  /* null check */
  if (NULL == nums || 0 >= numsSize) {
    return pivot_index;
  }

  /* get all sum */
  int array_sum = 0;
  for (int i = 0; i < numsSize; ++i) {
    array_sum += *(nums + i);
  }

  /* find the half point */
  int half_sum = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (half_sum*2 + *(nums+i) == array_sum) {
      pivot_index = i;
      break;
    }
    half_sum += *(nums + i);
  }

  return pivot_index;
}

int main(void) {

  int nums[] = {1, 7, 3, 6, 5, 6};
  int size = (sizeof(nums) / sizeof(nums[0]));

  printf("\r\nPivot Index: \t%d.\r\n", pivotIndex_2_Success(nums, size));

  return 0;
}