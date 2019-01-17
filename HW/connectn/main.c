#include <stdio.h>
#include <stdlib.h>
#include "cmd_check1.h"
#include "board.h"
#include "win.h"
#include "input_val.h"



void make_move(char** board, int num_rows, int col, char piece){
	int i;
	//this loop helps piece drops onto the upper position which has '*'
	for(i=0;i<num_rows;++i){
	if(board[i][col] != '*'){
		continue;
	}
	board[i][col] = piece;
	break;
	}
}

void declare_winner(char** board, int num_rows, int num_cols, int turn, int pieces){
	if(tied(board, num_rows, num_cols, pieces)){
		printf("Tie game!\n");
	}
	else if(turn == 0){
		printf("Player 2 Won!\n");
	}
	else{
		printf("Player 1 Won!\n");
	}
	
}

void play_game(char** board, int turn, int row_size, int col_size, int pieces_win){
	int col;
	char pieces[] = "XO";

	while(!is_game_over(board, row_size, col_size, pieces_win)){
		//display state of game to the user
		print_board(board, row_size, col_size);
		get_valid_move(board, row_size, col_size, &col);
		make_move(board, row_size, col, pieces[turn]);
		//change the turn
		turn = (turn + 1) % 2;
	}
	
	print_board(board, row_size, col_size); //print the board one final time
	declare_winner(board, row_size, col_size, turn, pieces_win);

}

int main(int argc, char* argv[]){
	int row_size, col_size, pieces;
	char** board;
	int turn;
	cmd_check(argc, argv);
	row_size = cmd_rows(argc, argv);
	col_size = cmd_cols(argc, argv);
	pieces = cmd_pieces(argc, argv);
	set_up(&board, &turn, row_size, col_size);
	play_game(board, turn, row_size, col_size, pieces);
	//print_board(board, size, size);
	clean_up(board, row_size);
	return 0;
}
