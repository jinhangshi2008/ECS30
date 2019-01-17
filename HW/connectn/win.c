#include "win.h"
//If either the won or tied is true, then the game is over
bool is_game_over(char** board, int num_rows, int num_cols, int pieces){
	return won(board, num_rows, num_cols, pieces) || 
				tied(board, num_rows, num_cols, pieces);
}
//If one of the winning type is true, then one of the players won
bool won(char** board, int num_rows, int num_cols, int pieces){
	return horz_win(board, num_rows, num_cols, pieces) || 
				 vert_win(board, num_rows, num_cols, pieces) || 
				 diag_win(board, num_rows, num_cols, pieces);
}
//when the number of same adjacent pieces in a horizontal line reaches the user's input condition, win
bool horz_win(char** board, int num_rows, int num_cols, int pieces){
	int i, j;
	int k = 0;
	for(i = 0; i < num_rows; ++i){
		for(j = 0; j < num_cols-1; ++j){      //j < num_cols-1 so j+1 does not get out of bounds
		if(board[i][j] == '*'){
			k = 0;
			continue;
		}
		if(board[i][j] == board[i][j+1]){    //k records the number of adjacent same pieces
			++k;
			}
		else if(board[i][j] != board[i][j+1]){
			k = 0;
		}
		if(k == pieces-1){
			return true;
		}
		}
		}
	return false;
}
//when the number of same adjacent pieces in a vertical line reaches the user's input condition, win
bool vert_win(char** board, int num_rows, int num_cols, int pieces){
	int i, j;
	int k = 0;

	for(i = 0; i < num_cols; ++i){
		for(j = num_rows-1; j >= 1; --j){     //j>=1 so j-1 does not get out of bounds
		if(board[j][i] == '*'){
			k = 0;
			continue;
			}
		if(board[j][i] == board[j-1][i]){
			++k;
		}
		else if(board[j][i] != board[j-1][i]){
			k = 0;
		}
		if(k == pieces - 1){
			return true;
		}
	}
	}
	return false;
}

bool diag_win(char** board, int num_rows, int num_cols, int pieces){
	return left_diag_win(board, num_rows, num_cols, pieces) || 
				 right_diag_win(board, num_rows, num_cols, pieces);
}

//when the number of same adjacent pieces in a diagonal line from bottom left to top right reaches the user's input condition, win
bool right_diag_win(char** board, int num_rows, int num_cols, int pieces){
int i, j;
int k = 0;
	for(i = 0; i < num_rows-1; ++i){
		for(j = 0; j < num_cols-1; ++j){
		if(board[i][j] == '*'){
				k = 0;
				continue;
			}
		if(board[i][j] == board[i+1][j+1]){
			k = k + 1;
			i = i + 1;
			if(k == pieces - 1){
			return true;
			}
		}
		else if(board[i][j] != board[i+1][j+1]){
			k = 0;
			break;
	}
	}
	}
	return false;
}
//when the number of same adjacent pieces in a horizontal line from bottom right to top left reaches the user's input condition, win
bool left_diag_win(char** board, int num_rows, int num_cols, int pieces){
int i, j;
int k = 0;
	for(i = 0; i < num_rows-2; ++i){
		for(j = num_cols - 1; j >= 1;--j){
			if(board[i][j] == '*'){
				continue;
			}
		    if(board[i][j] == board[i+1][j-1]){
		    k = k + 1;
			i = i + 1;
			if(k == pieces-1){
			return true;
		}
		}
		else if(board[i][j] != board[i+1][j-1]){
			k = 0;
			break;
		}

		}
}
	return false;
}
//when the board is full and no one wins, tied
bool tied(char** board, int num_rows, int num_cols, int pieces){
	return is_board_full(board, num_rows, num_cols) && 
				!won(board, num_rows, num_cols, pieces);
}

bool is_board_full(char** board, int num_rows, int num_cols){
	int i, j;
	
	for(i = 0; i < num_rows; ++i){
		for(j = 0; j < num_cols; ++j){
			if(board[i][j] == '*'){
				return false;
			}
		}
	}
	return true;

}


