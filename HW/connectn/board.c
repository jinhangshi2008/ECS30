#include <stdlib.h>
#include <stdio.h>
#include "board.h"

//this file makes and print the board for the game by using '*'
void set_up(char*** board, int *turn, int row_size, int col_size){
	*board = make_board(row_size, col_size);
	*turn = 0;
}
char** make_board(int num_rows, int num_cols){
	
	char** board = (char**)malloc((num_rows) * sizeof(char*));
	int i, j;
	
	for(i = 0; i < num_rows; ++i){
		board[i] = (char*)malloc((num_cols)*sizeof(char));
		for(j = 0; j < num_cols; ++j){
			board[i][j] = '*';
		}
	}
	return board;
}

void print_board(char** board, int num_rows, int num_cols){
	int i,j;
	
	for(i = num_rows - 1; i >= 0; --i){
		printf("%d ", i);
		for(j = 0; j < num_cols; ++j){
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	
	printf("  ");
	for(j = 0; j < num_cols; ++j){
		printf("%d ", j);
	}
	printf("\n");
}


void clean_up(char** board, int num_rows){
	int i;
	for(i = 0; i < num_rows; ++i){
		free(board[i]);
	}
	free(board);
}

