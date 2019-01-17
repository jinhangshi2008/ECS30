#include <ctype.h>
#include <stdio.h>
#include "input_val.h"

bool consume_stdin(){
	/*
		Consume the remaining characters on the standard input
		@returns: true if there are any non white space characters left
	*/
	char c;
	int num_chars_read = 0;
	bool leftovers = false;
	
	do{
		num_chars_read = scanf("%c", &c);
		if(!isspace(c)){
			leftovers = true;
		}
	}while(c != '\n' && num_chars_read > 0);
	return leftovers;
}

bool min_valid_requirements(int num_args_read, int num_args_needed, bool nothing_else){
	/*
		the minimum requirements for input to be valid, which is that we were are actually able
		to read something with scanf. If we fail to meet these requirements then the
		remaining characters on the standard input are consumed to allow for new input.
		@num_args_read: the number of arguments read by the last call to scanf
		@num_args_needed: the number of arguments we wanted to read in the last scanf 
		@nothing_else: true if we wanted only exactly the elements in the last scanf to be read
									 false if you are ok with their being extra input afterwards
		@returns: true if the last call to scanf successfully read all the elements
		@modfies: stdin
	*/
	
	bool leftovers = false;
	
	if(nothing_else || num_args_read != num_args_needed){
		leftovers = consume_stdin();
	}	

	return num_args_read == num_args_needed && !leftovers;
	
}

int get_int(char* prompt, bool nothing_else){
	/*	
		get an integer from the user
		@prompt: the prompt to be displayed to the user
		@nothing_else: true if we wanted only exactly the elements in the last scanf to be read
									 false if you are ok with their being extra input afterwards
		@returns: the first valid integer entered by the user
	*/
	
	int num;
	int num_args_read;

	do{
		printf("%s", prompt);
		num_args_read = scanf("%d", &num);
	}while(!min_valid_requirements(num_args_read, 1, nothing_else));
	return num;
}

int get_bound_int(char* prompt, bool nothing_else, int low, int high){
	/*
		get an integer from the user between low and high inclusive
		@prompt: the prompt to be displayed to the user
		@nothing_else: true if we wanted only exactly the elements in the last scanf to be read
									 false if you are ok with their being extra input afterwards
		@low: the minimum allowable value for the integer 
		@high: the maximum allowable value for the integer
		@returns: the first integer entered by the user between low and high
	
	*/

	int num;
	
	do{
		num = get_int(prompt, nothing_else);
	}while(!(num >= low && num <= high));

	return num;

}

void get_valid_move(char** board, int num_rows, int num_cols,
										 int* col){
	int num_args_read;
	do{
		printf("Enter a column between 0 and %d to play in: ", num_cols-1);
		num_args_read = scanf("%d", col);
	//read only one number at a time
	}while(!is_valid_move(num_args_read, 1, 
												board, *col, 
												num_rows, num_cols));						
										
}

bool is_valid_move(int num_args_read, int num_args_needed, 
									 char** board, int col,
									 int num_rows, int num_cols){

	bool leftovers = consume_stdin();
	if(num_args_read != num_args_needed){
		return false;
	}
	else if(leftovers){
		return false;
	}
	else if(!inbounds(col, num_rows, num_cols)){
		return false;
	}
	else if(board[num_rows-1][col] != '*'){
		return false;
	}
	else{
		return true;
	}
}

bool inbounds(int col, int num_rows, int num_cols){
	return col >= 0 && col < num_cols;
}

