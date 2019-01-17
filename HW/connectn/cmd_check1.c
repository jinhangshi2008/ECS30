#include "cmd_check1.h"
//this .c file checks the vadility of the command line input
//these three functions below read the input seperately
int cmd_rows(int argc, char* argv[]){
	int num_rows;
    sscanf(argv[1], "%d", &num_rows);
	return num_rows;
}
int cmd_cols(int argc, char* argv[]){
	int num_cols;
    sscanf(argv[2], "%d", &num_cols);
	return num_cols;
}
int cmd_pieces(int argc, char* argv[]){
	int num_pieces;
	sscanf(argv[3], "%d", &num_pieces);
    return num_pieces;
}
//if user enters either too many or too few inputs, the program will remind the user
void cmd_check(int argc, char* argv[]){
    int sum;
	sum = argc - 1;
    if(sum < 3){
		printf("Not enough arguments entered\nUsage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
		exit(0);
	}
	else if(sum > 3){
		printf("Too many arguments entered\nUsage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
		exit(0);
	}
}