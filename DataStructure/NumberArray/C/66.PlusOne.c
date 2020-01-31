#include <stdio.h>
#include <stdlib.h>

/**
 * @brief   要求：给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 *          最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 *          你可以假设除了整数 0 之外，这个整数不会以零开头。
 *          思路1：从后往前，连续的9变成0，如果全部变成0, 在最前面加1
 * @param   digits: 输入数组
 * @param   digitsSize: 输入数组的长度
 * @param   returnSize: 返回数组的长度
 * @retval  加1后的数组
*/
int *plusOne(int *digits, int digitsSize, int *returnSize) {

  /* null check */
  if (NULL == digits || 0 >= digits || NULL == returnSize) {
    return NULL;
  }

  int *ret_digits = NULL;
  *returnSize = 0;

  for (int i = digitsSize - 1; i >= 0; --i) {

    /* if meets 9, turn it to 0, else plus 1 */
    if (9 != *(digits + i)) {
      ++(*(digits + i));
      *returnSize = digitsSize;
      ret_digits = digits;
      return ret_digits;
    
    } else {
      *(digits + i) = 0;
    }
  }

  *returnSize = digitsSize + 1;
  ret_digits = (int *)malloc((size_t)(sizeof(int)*(*returnSize)));
  if (NULL == ret_digits) {
    return NULL;
  }

  *ret_digits = 1;
  for (int i = 0; i < digitsSize; ++i) {
    *(ret_digits + i + 1) = *(digits + i);
  }

  return ret_digits;
}

int main(void) {

  int digits[] = {9, 9, 9, 9};
  int size = sizeof(digits) / sizeof(digits[0]);
  
  int ret_size = 0;
  int *ret_dig = NULL;

  ret_dig = plusOne(digits, size, &ret_size);

  for (int i = 0; i < ret_size; ++i) {
    printf("%d, ", *(ret_dig + i));
  }

  return 0;
}