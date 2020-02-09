#include <stdio.h>
#include <string.h>

#define __LOG(name, x) printf("\r\n%s: %d\r\n", name, x)

/**
 * @brief   要求：编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
 *          不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题
 *          思路1：普通交换
 * @param   s: 字符串首地址
 * @param   sSize: 字符串长度
 * @retval  None
*/
void reverseString(char *s, int sSize) {

  if (NULL == s || 0 >=sSize) {
    return;
  }

  char swap = 0;
  for (unsigned int i = 0; i < sSize / 2; ++i) {
    swap = *(s + i);
    *(s + i) = *(s + (sSize - 1 - i));
    *(s + (sSize - 1 - i)) = swap;
  }
}

int main(void) {

  char str[] = "";
  int size = (int)strlen(str);

  printf("\r\nOriginal:\r\n%s\r\n", str);
  reverseString(str, size);
  printf("\r\nCurrent:\r\n%s\r\n", str);

  return 0;
}