#include <stdio.h>

void travel_array(char **grid, int max_row, int max_col) {
    for (int i = 0; i < max_row; ++i) {
        for (int j = 0; j < max_col; ++j) {
            printf("%c\t", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void modify(char **grid, int cur_row, int cur_col, int max_row, int max_col) {
    if (cur_row < 0 || cur_col < 0 || cur_row >= max_row || cur_col >= max_col || grid[cur_row][cur_col] != '1')
        return;
    grid[cur_row][cur_col] = '0';
    // travel_array(grid, max_row, max_col);
    modify(grid, cur_row - 1, cur_col, max_row, max_col);
    modify(grid, cur_row + 1, cur_col, max_row, max_col);
    modify(grid, cur_row, cur_col - 1, max_row, max_col);
    modify(grid, cur_row, cur_col + 1, max_row, max_col);
}

int numIslands(char **grid, int gridRowSize, int gridColSize) {
    int cnt_island = 0;
    if (gridColSize < 1 || gridColSize < 1 || grid == NULL) return 0;
    for (int i = 0; i < gridRowSize; ++i)
        for (int j = 0; j < gridColSize; ++j) {
            if (grid[i][j] == '1') {
                ++cnt_island;
                modify(grid, i, j, gridRowSize, gridColSize);
            }
        }
    
    return cnt_island;
}

int main(void) {
    char island[4][5] = {
        {'1','1','0','0','0'},
        {'1','1','0','1','1'},
        {'1','1','0','0','0'},
        {'0','0','0','1','0'}
    };

    char *p_arr[4];
    for (int i = 0; i < 4; ++i) {
        p_arr[i] = island[i];
    }
    char **p = (char**)&p_arr;
    
    printf("%d\n", numIslands(p, 4, 5));

    return 0;
}