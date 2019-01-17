#include "test.h"

void print_help(){

	printf("Commands:\n");
	printf("Help: h\n");
	printf("Quit: q\n");
	printf("Draw line: w row_start col_start row_end col_end\n");
	printf("Resize: r num_rows num_cols\n");
	printf("Add row or column: a [r | c] pos\n");
	printf("Delete row or column: d [r | c] pos\n");
	printf("Erase: e row col\n");
	printf("Save: s file_name\n");
	printf("Load: l file_name\n");
}

void input_identify(Board board){
    Board new_board;
    int save_num_cols, save_num_rows, i, j;
    char command1;
    int command7;
    char command2[10];
    int command3;
    int command4;
    int command5;
    char command6;
    FILE* fp;
    printf("Enter your command: ");
    while(command1 != 'q'){
        scanf("%c", &command1);
        if(command1 == 'q'){
            scanf("%c", &command1);
            if(command1 != '\n'){
                printf("Unrecognized command. Type h for help.\n");
                print_board(board);
                printf("Enter your command: ");
                scanf("%c", &command6);
                while(command6 != '\n'){
                scanf("%c", &command6);
                }
            }
            else{
                exit(0);
            }
        }
        else if(command1 == 'h'){
             scanf("%c", &command6);
             if(command6 != '\n'){
                printf("Unrecognized command. Type h for help.\n");
                print_board(board);
                printf("Enter your command: ");
                while(command6 != '\n'){
                scanf("%c", &command6);
                }
            }
            else{
                print_help();
                print_board(board);
                printf("Enter your command: ");
            }
        }
        else if(command1 == 'w'){
            scanf(" %d ", &command7);
            scanf("%d ", &command3);
            scanf("%d ", &command4);
            scanf("%d", &command5);
            scanf("%c", &command6);
            if(command6 == ' '){
                scanf("%c", &command6);
                if(command6 != '\n'){
                    printf("Improper draw command.\n");
                    print_board(board);
                    printf("Enter your command: ");
                    while(command6 != '\n'){
                    scanf("%c", &command6);
                    }
                }
            }
            else{
                if(command7 >= board.num_rows || command3 >= board.num_cols || command4 >= board.num_rows || command5 >= board.num_cols || command7 < 0 || command3 < 0 || command4 < 0 || command5 < 0){
                    printf("Improper draw command.\n");
                    print_board(board);
                    printf("Enter your command: ");
                }
                else if(command7 == command4){
                    modify_hori_board(board, &new_board, command7, command3, command5);
                    print_board(new_board);
                    board = new_board;
                    printf("Enter your command: ");
                }
                else if(command3 == command5){
                    modify_vert_board(board, &new_board, command3, command7, command4);
                    print_board(new_board);
                    board = new_board;
                    printf("Enter your command: ");   
                }
                else if(command7 - command4 == command5 - command3){
                    modify_right_diag_board(board, &new_board, command3, command5, command7, command4);
                    print_board(new_board);
                    board = new_board;
                    printf("Enter your command: ");
                }
                else if(command7 - command4 == command3 - command5){
                    modify_left_diag_board(board, &new_board, command3, command5, command7, command4);
                    print_board(new_board);
                    board = new_board;
                    printf("Enter your command: ");
                }
                else{
                    printf("Cannot draw the line as it is not straight.\n");
                    print_board(board);
                    printf("Enter your command: ");
                }
            }
        }
        else if(command1 == 'a'){
            scanf(" %c ", &command6);
            if(command6 == 'r'){
                scanf( "%s", command2);
                if(atoi(command2) > board.num_rows || atoi(command2) < 0){
                    printf("Improper add command.\n");
                    print_board(board);
                    printf("Enter your command: ");
                }
                else if(isdigit(command2[0])){
                    modify_row_board(board, &new_board, atoi(command2));
                    print_board(new_board);
                    board = new_board;
                    printf("Enter your command: ");
                }
                else{
                    scanf("%c", &command6);
                    while(command6 != '\n'){
                        scanf("%c", &command6);
                    }
                    printf("Improper add command.\n");
                    print_board(board);
                    printf("Enter your command: ");
                }
            }
            else if(command6 == 'c'){
                scanf( "%s", command2);
                if(atoi(command2) > board.num_cols || atoi(command2) < 0){
                    printf("Improper add command.\n");
                    print_board(board);
                    printf("Enter your command: ");
                }
                else{
                    modify_col_board(board, &new_board, atoi(command2));
                    print_board(new_board);
                    board = new_board;
                    printf("Enter your command: ");
                }
            }
        }
        else if(command1 == 'd'){
            scanf(" %c ", &command6);
            if(command6 == 'r'){
                scanf( "%s", command2);
                if(atoi(command2) >= board.num_rows || atoi(command2) < 0){
                    printf("Improper delete command.\n");
                    print_board(board);
                    printf("Enter your command: ");
                }
                else{
                    delete_row_board(board, &new_board, atoi(command2));
                    print_board(new_board);
                    board = new_board;
                    printf("Enter your command: ");
                }
            }
            else if(command6 == 'c'){
                scanf( "%s", command2);
                if(atoi(command2) >= board.num_cols || atoi(command2) < 0){
                    printf("Improper delete command.\n");
                    print_board(board);
                    printf("Enter your command: ");
                }
                else{
                    delete_col_board(board, &new_board, atoi(command2));
                    print_board(new_board);
                    board = new_board;
                    printf("Enter your command: ");
                }
            }
        }
        else if(command1 == 'r'){
            scanf( "%d ", &command3);
            scanf( "%d", &command4);
            if(command3 <= 0 || (command4 <= 0)){
                printf("Improper resize command.\n");
                print_board(board);
                printf("Enter your command: ");
            }
            else{
                resize_board(board, &new_board, command3, command4);
                print_board(new_board);
                board = new_board;
                printf("Enter your command: ");
            }
        }
        else if(command1 == 'e'){
            scanf( "%d ", &command3);
            scanf( "%d", &command4);
            if((command3 < 0) || (command4 < 0) || (command3 >= board.num_rows) || (command4 >= board.num_cols)){
                printf("Improper erase command.\n");
                print_board(board);
                printf("Enter your command: ");
            }
            else{
                erase_board(board, &new_board, command3, command4);
                print_board(new_board);
                board = new_board;
                printf("Enter your command: ");
            }
        }
        else if(command1 == 's'){
            scanf(" %s", command2);
            fp = fopen("file_name.bin", "wb");
            fwrite(board.the_board, sizeof(char**), board.num_cols*board.num_rows, fp);
            fclose(fp);
            print_board(board);
            save_num_cols = board.num_cols;
            save_num_rows = board.num_rows;
            printf("Enter your command: ");
        }
        else if(command1 == 'l'){
            scanf(" %s", command2);
            board.num_cols = save_num_cols;
            board.num_rows = save_num_rows;
            fp = fopen("file_name.bin", "rb");
            fread(board.the_board, sizeof(char**), board.num_cols*board.num_rows, fp);
            for(i = 0; i< board.num_rows; ++i){
                for(j = 0; j < board.num_cols; ++j){
                    fprintf(fp, "%c", board.the_board[i][j]);
                }
            }
            fclose(fp);
            printf("Enter your command: ");
        }
        else{
            scanf("%c", &command6);
            while(command6 != '\n'){
                scanf("%c", &command6);
            }
            printf("Unrecognized command. Type h for help.\n");
            print_board(board);
            printf("Enter your command: ");
        }
    }
}
