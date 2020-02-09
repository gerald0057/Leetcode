#include <stdio.h>
#include <string.h>

/**
 * @brief   要求：实现 strStr() 函数,
 *          给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回-1
 *          思路1：遍历
 * @param   haystack: 母串
 * @param   needle: 子串
 * @retval  存在的索引或-1
*/
int strStr(char* haystack, char* needle) {

  if (NULL == haystack || NULL == needle) return -1;

  int len_haystack = strlen(haystack), len_needle = strlen(needle);
  if (len_haystack < len_needle) return -1;
  if (len_needle == 0) return 0;

  unsigned char flag = 0;
  for (int i = 0; i <= len_haystack - len_needle; ++i) {
    flag = 0;
    if (haystack[i] == needle[0] &&
        haystack[i + len_needle - 1] == needle[len_needle - 1]) {
      for (int j = i + 1; j < i + len_needle - 1; ++j) {
        if (haystack[j] != needle[j - i]) {
          flag = 1;
          break;
        }
      }
      if (!flag) return i;
    }
  }

  return -1;
}

int main(void) {

  char haystack[] = "aaaabbaa", needle[] = "abbaa";

  printf("\r\nIndex:\t%d\r\n", strStr(haystack, needle));

  return 0;
}