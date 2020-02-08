#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief   要求：给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素
 *          思路1：标志位倒换，起点选择，方位判断
 * @param   matrix: 输入二维数组
 * @param   matrixSize: 输入数组的长度(二维数组的行数)
 * @param   matrixColSize: 输入数组的宽度(二维数组每行的列数)
 * @param   returnSize: 返回一维数组的长度
 * @retval  输出的数组
*/

int *findDiagonalOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize) {

  int *ret_matrix = NULL;

  /* null check */
  if (NULL == matrix || 0 >= matrixSize || NULL == matrixColSize || NULL == returnSize) {
    *returnSize = 0;
    return ret_matrix;
  }

  int row = matrixSize;
  int col = *matrixColSize;
  *returnSize = row * col;
  ret_matrix = (int *)malloc(sizeof(int) * (*returnSize));
  if (NULL == ret_matrix) {
    return ret_matrix;
  }
  memset(ret_matrix, 0, sizeof(int) * (*returnSize));

  int index = 0, dia_flag = 0;
  int pos_a = 0, pos_b = 0;

  /* every diagonal line has the same sum of x and y */
  for (int sum_xy = 0; sum_xy < col + row - 1; ++sum_xy) {

    /* find the start point */
    /* judging which part is being serch now, the left up part or the right down part */
    pos_a = sum_xy >= (0 == dia_flag ? row : col) ? (0 == dia_flag ? row-1 : col-1) : sum_xy;
    pos_b = sum_xy - pos_a;

    for (; pos_b < (0 == dia_flag ? col : row) && pos_a >= 0; ++pos_b, --pos_a) {

      *(ret_matrix + index++) = (0 == dia_flag ? *(*(matrix + pos_a) + pos_b) : *(*(matrix + pos_b) + pos_a));
    }

    dia_flag = !dia_flag;
  }

  return ret_matrix;
}

int main(void) {

  int matrix[][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };
  int *p_matrix[3];
  for (int i = 0; i < 3; ++i) {
    *(p_matrix + i) = *(matrix + i);
  }
  int matrixSize = sizeof(matrix) / sizeof(matrix[0]);
  int matrixColSize = sizeof(matrix[0]) / sizeof(matrix[0][0]);

  int retsize;
  int *ret_mat = findDiagonalOrder((int **)&p_matrix, matrixSize, &matrixColSize, &retsize);

  printf("\r\n[");
  for (int i = 0; i < retsize - 1; ++i) {
    printf("%d, ", *(ret_mat + i));
  } printf("%d]\r\n", *(ret_mat + retsize - 1));

  free(ret_mat);

  return 0;
}