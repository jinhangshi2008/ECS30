#ifndef WIN_H
	#define WIN_H
	#include <stdbool.h>
	
	bool is_game_over(char** board, int num_rows, int num_cols, int pieces);
	bool won(char** board, int num_rows, int num_cols, int pieces);
	bool horz_win(char** board, int num_rows, int num_cols, int pieces);
	bool vert_win(char** board, int num_rows, int num_cols, int pieces);
	bool diag_win(char** board, int num_rows, int num_cols, int pieces);
	bool left_diag_win(char** board, int num_rows, int num_cols, int pieces);
	bool right_diag_win(char** board, int num_rows, int num_cols, int pieces);
	bool tied(char** board, int num_rows, int num_cols, int pieces);
	bool is_board_full(char** board, int num_rows, int num_cols);
#endif
