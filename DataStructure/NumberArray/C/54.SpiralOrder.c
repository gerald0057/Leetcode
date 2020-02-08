#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/**
 * @brief   要求：给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素
 *          思路1：界定范围，索引加减
 * @param   matrix: 输入二维数组
 * @param   matrixSize: 输入数组的长度(二维数组的行数)
 * @param   matrixColSize: 输入数组的宽度(二维数组每行的列数)
 * @param   returnSize: 返回一维数组的长度
 * @retval  输出的数组
*/
int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize){

  int *ret_matrix = NULL;

  /* null check */
  if (NULL == matrix || 0 >= matrixSize || NULL == matrixColSize || NULL == returnSize) {
    *returnSize = 0;
    return ret_matrix;
  }

  int row = matrixSize;
  int col = *matrixColSize;
  int index = 0;
  *returnSize = row * col;
  ret_matrix = (int *)malloc(sizeof(int) * (*returnSize));
  if (NULL == ret_matrix) {
    return ret_matrix;
  }

  memset(ret_matrix, 0, sizeof(int) * (*returnSize));

  /* 框定上下左右四个范围 */
  int up, down, left, right;
  up = left = -1;
  right = col;
  down = row;

  /* 定义查找索引x和y， 定义竖直变化和水平变化的指示标志位 */
  int x = 0, y = 0;
  int v_flag = 0, h_flag = 1;

  while (index < *returnSize) {
    
    /* 取出对应数值 */
    ret_matrix[index] = matrix[y][x];
    ++index;

    /* 根据边界条件变化各个标志位 */
    /* 查找到右上角，改水平变化为竖直变化 */
    if (1 == h_flag && x >= right - 1 && y <= up + 1) {
      h_flag = 0;
      v_flag = 1;
      ++up;
    }
    /* 右下角 */
    else if (1 == v_flag && y >= down - 1 && x >= right - 1) {
      h_flag = -1;
      v_flag = 0;
      --right;
    }
    /* 左下角 */
    else if (-1 == h_flag && x <= left + 1 && y >= down - 1) {
      h_flag = 0;
      v_flag = -1;
      --down;
    }
    /* 左上角 */
    else if (-1 == v_flag && y <= up + 1 && x <= left + 1) {
      h_flag = 1;
      v_flag = 0;
      ++left;
    }
    
    /* 根据水平变化标志位 变化x */
    if (1 == h_flag) { ++x; }
    else if (-1 == h_flag) { --x; }

    /* 根据垂直变化标志位 变化y */
    if (1 == v_flag) { ++y; }
    else if (-1 == v_flag) { --y; }
  }

  return ret_matrix;
}

int main(void) {
  
#define WIDE 2
#define DEEP 2

  int mat[][WIDE] = {
    {1, 2},
    {4, 3},
  };
  int *p_mat[DEEP];
  for (unsigned int i = 0; i < DEEP; ++i) {
    *(p_mat + i) = (int *)mat[i];
  }
  int size = sizeof(mat) / sizeof(mat[0]);
  int colsize = sizeof(mat[0]) / sizeof(mat[0][0]);

  int retsize = 0;
  int *ret = spiralOrder((int **)&p_mat, size, &colsize, &retsize);

  if (NULL == ret) {
    printf("Error Execute, Exit With <NULL>.\n");
  }

  for (int i = 0; i < retsize; ++i) {
    printf("%d ", ret[i]);
  } printf("\n");

  free(ret);
  ret = NULL;

  return 0;
}