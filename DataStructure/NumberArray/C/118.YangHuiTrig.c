#include <stdio.h>
#include <stdlib.h>

/* free */
void free_mat(int **mat, int numRows);

/**
 * @brief   要求：给定一个非负整数 numRows，生成杨辉三角的前 numRows 行
 *          思路1：两端补零，中间由上一行两两相加得到
 * @param   numRows: 需要的杨辉三角的行数
 * @param   returnSize: 返回二维数组的长度（行数）
 * @param   returnColumnSizes: 返回二维数组的宽度（每行列数）
 * @retval  输出的数组
*/
int **generate(int numRows, int *returnSize, int **returnColumnSizes) {

  if (NULL == returnSize) {
    return NULL;
  }

  int **ret_mat = NULL;
  if (NULL == (ret_mat = (int **)malloc(sizeof(int *) * numRows))) {
    return NULL;
  }
  
  *returnSize = numRows;
  if (NULL == *returnColumnSizes) {
    *returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
  }
  
  int *ret_line = NULL;
  for (int i = 0; i < numRows; ++i) {

    /* malloc */
    ret_line = (int *)malloc(sizeof(int) * (i + 1));
    if (NULL == ret_line) {
      free_mat(ret_mat, numRows);
      free(returnSize);
      free_mat(returnColumnSizes, numRows);
      return NULL;
    }

    /* add head and tail */
    *(ret_line) = 1;
    *(ret_line + i) = 1;
    (*returnColumnSizes)[i] = i + 1;

    /* fill the middle, if need */
    int *last_line = NULL;
    for (int j = 1; j < i; ++j) {
      last_line = *(ret_mat + i - 1);
      *(ret_line + j) = *(last_line + j - 1) + *(last_line + j);
    }

    *(ret_mat + i) = ret_line;
  }
  return ret_mat;
}

void free_mat(int **mat, int numRows) {

  int *cur_line = NULL;
  for (int i = 0; i < numRows; ++i) {
    cur_line = *(mat + i);
    if (NULL != cur_line) {
      free(cur_line);
    }
  }
  free(mat);
}

int main(void) {

  int ret_size = 0;
  int *ret_colsize = NULL;
  int **ret_mat = generate(15, &ret_size, &ret_colsize);

  printf("[\r\n");
  for (int i = 0; i < ret_size; ++i) {
    printf("\t[");
    for (int j = 0; j < *(ret_colsize + i) - 1; ++j) {
      printf("%d, ", *(*(ret_mat + i) + j));
    } printf("%d], \r\n", *(*(ret_mat + i) + *(ret_colsize + i) - 1));
  } printf("]\r\n");

  free_mat(ret_mat, ret_size);
  free(ret_colsize);

  return 0;
}
