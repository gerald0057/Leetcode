#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define __LOG(name, x) printf("%s: %c\r\n", name, x)

/**
 * @brief   要求：给定两个二进制字符串，返回他们的和（用二进制表示）。输入为非空字符串且只包含数字 1 和 0。
 *          思路1：使用一个寄存器变量做加法，通过移位得到每一个二进制位
 * @param   matrix: 输入二维数组
 * @param   matrixSize: 输入数组的长度(二维数组的行数)
 * @param   matrixColSize: 输入数组的宽度(二维数组每行的列数)
 * @param   returnSize: 返回一维数组的长度
 * @retval  输出的数组
*/
char *addBinary(char *a, char *b) {

  int len_a = strlen(a), len_b = strlen(b);
  
  /* reserve space for \0 and the carry bit */
  int len_ret = (len_a > len_b ? len_a : len_b) + 2;

  char *ret_str = (char *)malloc(sizeof(char) * len_ret);
  if (NULL == ret_str) {
    return NULL;
  }
  memset(ret_str, 0, sizeof(char) * len_ret);

  int carry = 0;
  int index = len_ret - 2;
  while (len_a > 0 || len_b > 0 || carry == 1) {
    carry += len_a > 0 ? *(a + --len_a) - '0' : 0;
    carry += len_b > 0 ? *(b + --len_b) - '0' : 0;
    *(ret_str + index) = (char)(carry & 0x1) + '0';
    --index;
    carry >>= 1;
  }

  if (0 == *(ret_str)) {
    char *del = ret_str;
    ret_str = (char *)malloc(sizeof(char) * len_ret - 1);
    if (NULL == ret_str) {
      return NULL;
    }
    strcpy(ret_str, del + 1);
    free(del);
  }

  return ret_str;
}

int main(void) {
  char str_1[] = "", str_2[] = "";

  char *ret = addBinary(str_1, str_2);
  printf("%s\n", ret);
  free(ret);

  return 0;
}