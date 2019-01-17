#include "board.h"

void set_up(Board* board, int row_size, int col_size){
	*board = make_board(row_size, col_size);
}
Board make_board(int num_rows, int num_cols){
	Board board;
	int i, j;
	board.num_rows = num_rows;
	board.num_cols = num_cols;
	board.the_board = (char**)malloc((board.num_rows) * sizeof(char*));
	for(i = 0; i < num_rows; ++i){
		board.the_board[i] = (char*)malloc((board.num_cols)*sizeof(char));
		for(j = 0; j < board.num_cols; ++j){
			board.the_board[i][j] = '*';
		}
	}
	return board;
}

void print_board(Board board){
	int i,j;
	
	for(i = board.num_rows - 1; i >= 0; --i){
		printf("%d ", i);
		for(j = 0; j < board.num_cols; ++j){
			printf("%c ", board.the_board[i][j]);
		}
		printf("\n");
	}
	
	printf("  ");
	for(j = 0; j < board.num_cols; ++j){
		printf("%d ", j);
	}
	printf("\n");
}

void clean_up(Board board){
	int i;
	for(i = 0; i < board.num_rows; ++i){
		free(board.the_board[i]);
	}
	free(board.the_board);
}

void modify_hori_board(Board board, Board* new_board, int row, int col1, int col2){
	int i;
	*new_board = board;
	if(col1>col2){
		for(i=col2;i<=col1;++i){
			if(new_board->the_board[row][i] != '*'){
				if(new_board->the_board[row][i] == '-'){
					continue;
				}
				else{
					new_board->the_board[row][i] = '+';
				}
			}
			else{
				new_board->the_board[row][i] = '-';
			}
		}
	}
	else{
		for(i=col1;i<=col2;++i){
			if(new_board->the_board[row][i] != '*'){
				if(new_board->the_board[row][i] == '-'){
					continue;
				}
				else{
					new_board->the_board[row][i] = '+';
				}
			}
			else{
				new_board->the_board[row][i] = '-';
			}
		}
	}
}

void modify_vert_board(Board board, Board* new_board, int col, int row1, int row2){
	int i;
	*new_board = board;
	if(row1>row2){
		for(i=row2;i<=row1;++i){
			if(new_board->the_board[i][col] != '*'){
				if(new_board->the_board[i][col] == '|'){
					continue;
				}
				else{
					new_board->the_board[i][col] = '+';
				}
			}
			else{
				new_board->the_board[i][col] = '|';
			}
		}
	}
	else{
		for(i=row1;i<=row2;++i){
			if(new_board->the_board[i][col] != '*'){
				if(new_board->the_board[i][col] == '|'){
					continue;
				}
				else{
					new_board->the_board[i][col] = '+';
				}
			}
			else{
				new_board->the_board[i][col] = '|';
			}
		}
	}
}

void modify_right_diag_board(Board board, Board* new_board, int col1, int col2, int row1, int row2){
	int i;
	*new_board = board;
	if(row1>row2){
		for(i = row1; i >= row2; --i){
			if(new_board->the_board[i][col1] != '*'){
				if(new_board->the_board[i][col1] == '\\'){
					col1++;
					continue;
				}
				else{
					new_board->the_board[i][col1] = '+';
					col1++;
				}
			}
			else{
				new_board->the_board[i][col1] = '\\';
				col1++;
			}
		}
	}
	else{
		for(i = row2; i >= row1; --i){
			if(new_board->the_board[i][col2] != '*'){
				if(new_board->the_board[i][col2] == '\\'){
					col2++;
					continue;
				}
				else{
					new_board->the_board[i][col2] = '+';
					col2++;
				}
			}
			else{
				new_board->the_board[i][col2] = '\\';
				col2++;
			}
		}
	}
}

void modify_left_diag_board(Board board, Board* new_board, int col1, int col2, int row1, int row2){
	int i;
	*new_board = board;
	if(row1>row2){
		for(i = row2; i <= row1; ++i){
			if(new_board->the_board[i][col2] != '*'){
				if(new_board->the_board[i][col2] == '/'){
					col2++;
					continue;
				}
				else{
					new_board->the_board[i][col2] = '+';
					col2++;
				}
			}
			else{
				new_board->the_board[i][col2] = '/';
				col2++;
			}
		}
	}
	else{
		for(i = row1; i <= row2; ++i){
			if(new_board->the_board[i][col1] != '*'){
				if(new_board->the_board[i][col1] == '/'){
					col1++;
					continue;
				}
				else{
					new_board->the_board[i][col1] = '+';
					col1++;
				}
			}
			else{
				new_board->the_board[i][col1] = '/';
				col1++;
			}
		}
	}
}

void modify_row_board(Board board, Board* new_board, int row){
	int i, j;
	*new_board = board;
	new_board->the_board = (char**)realloc(new_board->the_board, (new_board->num_rows+1)*sizeof(char*));
	new_board->the_board[new_board->num_rows] = (char*)malloc((new_board->num_cols)*sizeof(char));
	if(row < new_board->num_rows){
		for(i = new_board->num_rows-1; i >= row; --i){
			for(j = 0; j < new_board->num_cols+1; ++j){
				new_board->the_board[i+1][j] = new_board->the_board[i][j];
				new_board->the_board[i][j] = '*';
			}
		}
	}
	else if(row == new_board->num_rows){
		for(j = 0; j < new_board->num_cols+1; ++j){
			new_board->the_board[row][j] = '*';
		}
	}
	new_board->num_rows++;
}

void modify_col_board(Board board, Board* new_board, int col){
	int i, j;
	*new_board = board;
	for(i = 0; i <new_board->num_rows ; ++i){
		new_board->the_board[i] = (char*)realloc(new_board->the_board[i], (new_board->num_cols+1)*sizeof(char));
		if(col < new_board->num_cols){	
			for(j = new_board->num_cols - 1; j >= col ; --j){
				new_board->the_board[i][j+1] = new_board->the_board[i][j];
				new_board->the_board[i][j] = '*';
			}
		}
		else if(col == new_board->num_cols){
			new_board->the_board[i][col] = '*';
		}
	}
	new_board->num_cols++;
}

void delete_row_board(Board board, Board* new_board, int row){
	int i, j;
	*new_board = board;
	new_board->num_rows--;
	for(i = row; i < new_board->num_rows; ++i){
		for(j = 0; j < new_board->num_cols; ++j){
			new_board->the_board[i][j] = new_board->the_board[i+1][j];
		}
	}
	new_board->the_board = (char**)realloc(new_board->the_board, (new_board->num_rows)*sizeof(char*));
}

void delete_col_board(Board board, Board* new_board, int col){
	int i, j;
	*new_board = board;
	new_board->num_cols--;
	for(i = 0; i < new_board->num_rows; ++i){
		for(j = col; j < new_board->num_cols; ++j){
			new_board->the_board[i][j] = new_board->the_board[i][j+1];
		}
		new_board->the_board = (char**)realloc(new_board->the_board, (new_board->num_cols)*sizeof(char*));
	}
}

void resize_board(Board board, Board* new_board, int num_rows, int num_cols){
	int i, j;
	*new_board = board;
	if((new_board->num_cols >= num_cols) && (new_board->num_rows >= num_rows)){
		new_board->num_cols = num_cols;
		new_board->num_rows = num_rows;
		new_board->the_board = (char**)realloc(new_board->the_board, (new_board->num_rows) * sizeof(char*));
		for(i = 0; i < new_board->num_rows; ++i){
			new_board->the_board[i] = (char*)realloc(new_board->the_board[i], (new_board->num_cols) * sizeof(char));
		}
	}
	else if((new_board->num_cols >= num_cols) && (new_board->num_rows < num_rows)){
		new_board->the_board = (char**)realloc(new_board->the_board, (num_rows) * sizeof(char*));
		for(i = 0; i < num_rows; ++i){
			new_board->the_board[i] = (char*)realloc(new_board->the_board[i], (num_cols) * sizeof(char));
		}
		for(i = new_board->num_rows; i < num_rows; ++i){
			for(j = 0; j < num_cols; ++j){
				new_board->the_board[i][j] = '*';
			}
		}
		new_board->num_cols = num_cols;
		new_board->num_rows = num_rows;
	}
	else if((new_board->num_cols < num_cols) && (new_board->num_rows >= num_rows)){
		new_board->the_board = (char**)realloc(new_board->the_board, (num_rows) * sizeof(char*));
		for(i = 0; i < num_rows; ++i){
			new_board->the_board[i] = (char*)realloc(new_board->the_board[i], (num_cols) * sizeof(char));
			for(j = new_board->num_cols; j < num_cols; ++j){
				new_board->the_board[i][j] = '*';
			}
		}
		new_board->num_cols = num_cols;
		new_board->num_rows = num_rows;
	}
	else if((new_board->num_cols < num_cols) && (new_board->num_rows < num_rows)){
		new_board->the_board = (char**)realloc(new_board->the_board, (num_rows) * sizeof(char*));
		for(i = 0; i < num_rows; ++i){
			new_board->the_board[i] = (char*)realloc(new_board->the_board[i], (num_cols) * sizeof(char));
		}
		for(i = new_board->num_rows; i < num_rows; ++i){
			for(j = 0; j < num_cols; ++j){
				new_board->the_board[i][j] = '*';
			}
		}
		for(i = 0; i < new_board->num_rows; ++i){
			for(j = new_board->num_cols; j < num_cols; ++j){
				new_board->the_board[i][j] = '*';
			}
		}
		new_board->num_cols = num_cols;
		new_board->num_rows = num_rows;
	}
}

void erase_board(Board board, Board* new_board, int row, int col){
	*new_board = board;
	new_board->the_board[row][col] = '*';
}