#ifndef BOARD_H
	#define BOARD_H
    #include <stdio.h>
    #include <stdlib.h>
    typedef struct Board_Struct{
	char** the_board;
	int num_rows;
	int num_cols;
} Board;
	void set_up(Board* board, int row_size, int col_size);
	Board make_board(int num_rows, int num_cols);
	void print_board(Board board);
	void clean_up(Board board);
	void modify_hori_board(Board board, Board* new_board, int row, int col1, int col2);
	void modify_vert_board(Board board, Board* new_board, int col, int row1, int row2);
	void modify_right_diag_board(Board board, Board* new_board, int col1, int col2, int row1, int row2);
	void modify_left_diag_board(Board board, Board* new_board, int col1, int col2, int row1, int row2);
	void modify_row_board(Board board, Board* new_board, int row);
	void modify_col_board(Board board, Board* new_board, int col);
	void delete_row_board(Board board, Board* new_board, int row);
	void delete_col_board(Board board, Board* new_board, int col);
	void resize_board(Board board, Board* new_board, int num_rows, int num_cols);
	void erase_board(Board board, Board* new_board, int row, int col);
#endif
