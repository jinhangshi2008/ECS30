#ifndef BOARD_H
	#define BOARD_H
	void set_up(char*** board, int *turn, int row_size, int col_size);
	char** make_board(int num_rows, int num_cols);
	void print_board(char** board, int num_rows, int num_cols);
	void clean_up(char** board, int num_rows);
#endif
