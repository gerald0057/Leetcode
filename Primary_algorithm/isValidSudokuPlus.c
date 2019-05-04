#include <stdio.h>

int isValidSudoku(char (*board)[9], int boardRowSize, int boardColSize) {
    unsigned int RowArr[9][10] = {0}, ColArr[9][10] = {0}, ZoneArr[9][10] = {0};
   
	int i = 0, j = 0;
	for (; i < boardRowSize; ++i){
		for (j = 0; j < boardColSize; ++j){
			if (board[i][j] != '.'){
				int num = board[i][j] - '0';
				if (RowArr[i][num] || ColArr[j][num] || ZoneArr[(i / 3) * 3 + j / 3][num]){
					// printf("Error located at: %d, %d\n", i + 1, j + 1);
					return 0;
				}					
				else{
					RowArr[i][num] = 1;
					ColArr[j][num] = 1;
					ZoneArr[(i / 3) * 3 + j / 3][num] = 1;
				}
			}
		}
	}

    return 1;
}


int main(void) {
	char board[][9] = {
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};

	if (isValidSudoku(board, 9, 9))
		puts("True");
	else
		puts("False");

	return 0;
}