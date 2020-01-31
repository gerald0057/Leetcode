#include <stdio.h>

int main(void) {
    char arr[4][5] = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','6','7','0'},
        {'4','0','0','0','0'}
    };

    for (int i = 0; i < 4; ++i) {
        for (int j = 0 ; j < 5; ++j) {
            printf("%x\t", &arr[i][j]);
        }
        printf("\n");
    }

    char **p;
    char *p_arr[4];
    for (int i = 0; i < 4; ++i) {
        p_arr[i] = arr[i];
    }
    p = &p_arr;
    // printf("%x\n", &p_arr);
    for (int i = 0; i < 4; ++i) {
        printf("%x\t%x\t%c\n", &p_arr[i], p_arr[i], *p_arr[i]);
    }

    printf("%x\t%x\t%x\t%c\n", &p, p, *p, *(*(p + 2) + 3));
    return 0;
}