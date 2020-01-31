#include <stdio.h>
#include <stdlib.h>

int containDuplicates(char* ch, int size) {
	int i = 0;
	for (; i < size - 1; ++i)
		if (ch[i] == ch[i + 1] && ch[i] != '.')
			return 1;
	return 0;
}

void qsortCHAR(char* ch, int pos_former, int pos_latter) {
	if (pos_former < pos_latter)
	{
		int i = pos_former, j = pos_latter;
		char x = ch[pos_former];
		while (i < j) {
			while (i < j && ch[j] >= x)
				--j;
			if (i < j)
				ch[i++] = ch[j];

			while (i < j && ch[i] <= x)
				++i;
			if (i < j)
				ch[j--] = ch[i];
		}

		ch[i] = x;
		qsortCHAR(ch, pos_former, i - 1);
		qsortCHAR(ch, i + 1, pos_latter);
	}
}

int RowTestDone(char* Row, int size) {
	if (size < 1) {
		perror("error in broad size");
		exit(1);
	}

	int i = 0;
	char* tempRow = NULL;
	if (NULL == (tempRow = (char*)malloc(sizeof(char) * size))) {
		perror("error in molloc");
		exit(2);
	}
	for (i = 0; i < size; ++i)
		tempRow[i] = Row[i];
	qsortCHAR(tempRow, 0, 8);
	if (containDuplicates(tempRow, size)) {
		free(tempRow);
		tempRow = NULL;
		return 0;
	}

	free(tempRow);
	tempRow = NULL;
	return 1;
}

int ColTestDone(char(*board)[9], int size) {
	int i = 0, j = 0;
	char ch[9];
	for (; i < size; ++i) {
		for (j = 0; j < size; ++j)
			ch[j] = board[j][i];
		qsortCHAR(ch, 0, 8);
		if (containDuplicates(ch, 9))
			return 0;
	}

	return 1;
}

int ZoneTestDone(char(*board)[9], int size) {
	int i = 0, j = 0;
	char zone[9][10];
	int index[9] = { 0 };
	for (; i < size; ++i)
		for (j = 0; j < size; ++j)
			zone[(i / 3) * 3 + j / 3][index[(i / 3) * 3 + j / 3]++] = board[i][j];

	for (i = 0; i < size; ++i)
		zone[i][9] = '\0';

	for (i = 0; i < size; ++i) {
		qsortCHAR(zone[i], 0, 8);
		if (containDuplicates(zone[i], 9))
			return 0;
	}

	return 1;
}

int isValidSudoku(char(*board)[9], int boardRowSize, int boardColSize) {
	int i = 0;
	for (; i < boardRowSize; ++i) {
		if (!RowTestDone(board[i], boardColSize))
			return 0;
	}

	i = 0;
	for (; i < boardColSize; ++i) {
		if (!ColTestDone(board, boardRowSize))
			return 0;
	}

	if (!ZoneTestDone(board, 9))
		return 0;

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



