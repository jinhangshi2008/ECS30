#ifndef INPUT_VAL_H
	#define INPUT_VAL_H

	#include <stdbool.h>
	bool consume_stdin();
	bool min_valid_requirements(int num_args_read, int num_args_needed, bool nothing_else);
	int get_int(char* prompt, bool nothing_else);
	int get_bound_int(char* prompt, bool nothing_else, int low, int high);
	void get_valid_move(char** board, int num_rows, int num_cols,
										int* col);
	bool is_valid_move(int num_args_read, int num_args_needed, 
									 char** board, int col,
									 int num_rows, int num_cols);
	bool inbounds(int col, int num_rows, int num_cols);

#endif
