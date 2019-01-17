#include "cmd_check.h"
//this .c file checks the vadility of the command line input
//these two functions below read the input seperately
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
void cmd_check(int argc, char* argv[], Board* board1){
    Board board;
    if(argc == 1){
        set_up(&board, 10, 10);
        print_board(board);
        }
    else if(argc == 2){
        set_up(&board, 10, 10);
        print_board(board);
        }
    else if(argc == 3){
        if(((isdigit(argv[1][0])) && (isdigit(argv[2][0]))) || ((isdigit(argv[1][0])) && (argv[2][0] == '-')) ){
            if(atoi(argv[1]) <= 0){
                printf("The number of rows is less than 1.\n");
                printf("Making default board of 10 X 10.\n");
                set_up(&board, 10, 10);
                print_board(board);
            }
            else if(atoi(argv[2]) <= 0){
                printf("The number of columns is less than 1.\n");
                printf("Making default board of 10 X 10.\n");
                set_up(&board, 10, 10);
                print_board(board);
            }
            else{
                set_up(&board, cmd_rows(argc, argv), cmd_cols(argc, argv));
                print_board(board);   
            }
        }
        else if(!(isdigit(argv[1][0]))){
            printf("The number of rows is not an integer.\n");
            printf("Making default board of 10 X 10.\n");
            set_up(&board, 10, 10);
            print_board(board);
        }
        else if(!(isdigit(argv[2][0]))){
            printf("The number of columns is not an integer.\n");
            printf("Making default board of 10 X 10.\n");
            set_up(&board, 10, 10);
            print_board(board);
        }
    }
    else{
        if(argc == 4){
            printf("Wrong number of command line arguements entered.\n");
            printf("Usage: ./paint.out [num_rows num_cols]\n");
            printf("Making default board of 10 X 10.\n");
            set_up(&board, 10, 10);
            print_board(board);
        }
        else{
            printf("Usage: ./paint.out [num_rows num_cols]\n");
            printf("Making default board of 10 X 10.\n");
            set_up(&board, 10, 10);
            print_board(board);
        }
    }
    *board1  = board;
}