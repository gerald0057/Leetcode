#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define __LOG(name, x) printf("%s: %ld\r\n", name, x)

/**
 * @brief   要求：编写一个函数来查找字符串数组中的最长公共前缀。如果不存在公共前缀，返回空字符串 ""。
 *          思路1：在第一个字符串的基础上向后遍历，遇到不一样的地方改为\0，使得最长公共子串不停地缩短
 * @param   haystack: 母串
 * @param   needle: 子串
 * @retval  最长公共子串
*/
char *longestCommonPrefix(char **strs, int strsSize) {

  size_t len = 0;

  if (NULL == strs || 0 >= strsSize) {
    len = 0;
  } else {
    len = strlen(*strs);
  }

  char *ret_str = (char *)malloc(sizeof(char) * (len + 1));
  if (NULL == ret_str) {
    return NULL;
  }
  memset(ret_str, 0, sizeof(char) * (len + 1));

  if (0 == len) {
    return ret_str;
  }

  strcpy(ret_str, *strs);

  for (int i = 1; i < strsSize; ++i) {
    for (int j = 0; *(ret_str + j) != '\0'; ++j) {
      if (*(ret_str + j) != *(*(strs + i) + j)) {
        *(ret_str + j) = '\0';
        break;
      }
    }
  }

  return ret_str;
}

int main(void) {
  char *strs[] = {"flower","flow","flight"};
  int strsSize = sizeof(strs) / sizeof(strs[0]);

  char *ret = longestCommonPrefix(strs, strsSize);

  printf("%s", ret);
  free(ret);

  return 0;
}