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
    char command1[10];
    char command6;
    char command2[10];
    char save_file[10];
    char command3[10];
    char command4[10];
    char command5[10];
    FILE* fp;
    printf("Enter your command: ");
    //create a infinite loop first
    while(command1[0] != 'q'){
        scanf("%s", command1);
        //divide commands into cases
        // seperate scanf helps different commands' formats
        if(command1[0] == 'q'){
            scanf("%c", &command6);
            if(command6 != '\n'){
                while(command6 != '\n'){
                    scanf("%c", &command6);
                }
                printf("Unrecognized command. Type h for help.\n");
                print_board(board);
                printf("Enter your command: ");
            }
            else{
                exit(0);
            }
        }
        else if(command1[0] == 'h'){
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
        else if(command1[0] == 'w'){
            scanf( "%s ", command2);
            scanf("%s ", command3);
            scanf("%s ", command4);
            scanf("%s", command5);
            scanf("%c", &command6);
            if(command6 != '\n' || atoi(command2) >= board.num_rows || atoi(command3) >= board.num_cols || atoi(command4) >= board.num_rows || atoi(command5) >= board.num_cols || atoi(command2) < 0 || atoi(command3) < 0 || atoi(command4) < 0 || atoi(command5) < 0){
                if(command6 == ' '){
                    scanf("%c", &command6);
                    if(command6 != '\n'){
                        while(command6 != '\n'){
                            scanf("%c", &command6);
                        }
                        printf("Improper draw command.\n");
                        print_board(board);
                        printf("Enter your command: ");
                    }
                    else if(atoi(command2) == atoi(command4)){
                        modify_hori_board(board, &new_board, atoi(command2), atoi(command3), atoi(command5));
                        print_board(new_board);
                        board = new_board;
                        printf("Enter your command: ");
                    }
                    else if(atoi(command3) == atoi(command5)){
                        modify_vert_board(board, &new_board, atoi(command3), atoi(command2), atoi(command4));
                        print_board(new_board);
                        board = new_board;
                        printf("Enter your command: ");   
                    }
                    else if(atoi(command2) - atoi(command4) == atoi(command5) - atoi(command3)){
                        modify_right_diag_board(board, &new_board, atoi(command3), atoi(command5), atoi(command2), atoi(command4));
                        print_board(new_board);
                        board = new_board;
                        printf("Enter your command: ");
                    }
                    else if(atoi(command2) - atoi(command4) == atoi(command3) - atoi(command5)){
                        modify_left_diag_board(board, &new_board, atoi(command3), atoi(command5), atoi(command2), atoi(command4));
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
                else{
                   while(command6 != '\n'){
                        scanf("%c", &command6);
                    }
                    printf("Improper draw command.\n");
                    print_board(board);
                    printf("Enter your command: ");
                }
            }
            //compare the inputs to decide which kind of line the user wants to draw
            else if(atoi(command2) == atoi(command4)){
                modify_hori_board(board, &new_board, atoi(command2), atoi(command3), atoi(command5));
                print_board(new_board);
                board = new_board;
                printf("Enter your command: ");
            }
            else if(atoi(command3) == atoi(command5)){
                modify_vert_board(board, &new_board, atoi(command3), atoi(command2), atoi(command4));
                print_board(new_board);
                board = new_board;
                printf("Enter your command: ");   
            }
            else if(atoi(command2) - atoi(command4) == atoi(command5) - atoi(command3)){
                modify_right_diag_board(board, &new_board, atoi(command3), atoi(command5), atoi(command2), atoi(command4));
                print_board(new_board);
                board = new_board;
                printf("Enter your command: ");
            }
            else if(atoi(command2) - atoi(command4) == atoi(command3) - atoi(command5)){
                modify_left_diag_board(board, &new_board, atoi(command3), atoi(command5), atoi(command2), atoi(command4));
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
        else if(command1[0] == 'a'){
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
        else if(command1[0] == 'd'){
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
                else if(isdigit(command2[0])){
                    delete_col_board(board, &new_board, atoi(command2));
                    print_board(new_board);
                    board = new_board;
                    printf("Enter your command: ");
                }
                else{
                    scanf("%c", &command6);
                    while(command6 != '\n'){
                        scanf("%c", &command6);
                    }
                    printf("Improper delete command.\n");
                    print_board(board);
                    printf("Enter your command: ");
                }
            }
        }
        else if(command1[0] == 'r'){
            scanf( "%s ", command2);
            scanf( "%s", command3);
            if((atoi(command2) <= 0) || (atoi(command3) <= 0)){
                printf("Improper resize command.\n");
                print_board(board);
                printf("Enter your command: ");
            }
            else{
                resize_board(board, &new_board, atoi(command2), atoi(command3));
                print_board(new_board);
                board = new_board;
                printf("Enter your command: ");
            }
        }
        else if(command1[0] == 'e'){
            scanf( "%s ", command2);
            scanf( "%s", command3);
            if((atoi(command2) < 0) || (atoi(command3) < 0) || (atoi(command2) >= board.num_rows) || (atoi(command3) >= board.num_cols)){
                printf("Improper erase command.\n");
                print_board(board);
                printf("Enter your command: ");
            }
            else{
                erase_board(board, &new_board, atoi(command2), atoi(command3));
                print_board(new_board);
                board = new_board;
                printf("Enter your command: ");
            }
        }
        else if(command1[0] == 's'){
            scanf(" %s", command2);
            strcpy(save_file, command2);
            fp = fopen("file_name.bin", "wb");
            fwrite(board.the_board, sizeof(char**), board.num_cols*board.num_rows, fp);
            fclose(fp);
            print_board(board);
            save_num_cols = board.num_cols;
            save_num_rows = board.num_rows;
            printf("Enter your command: ");
        }
        else if(command1[0] == 'l'){
            scanf(" %s", command2);
            if(command2[0] == 'm'){
                scanf("%c", &command6);
                while(command6 != '\n'){
                    scanf("%c", &command6);
                }
                printf("Failed to open file: monkey_butts\n");
                print_board(board);
                printf("Enter your command: ");
            }
            else if(command2[0] == 'x'){
                new_board = make_board(10, 10);
                board = new_board;
                modify_right_diag_board(board, &new_board, 9, 0, 0, 9);
                board = new_board;
                modify_left_diag_board(board, &new_board, 9, 0, 9, 0);
                board = new_board;
                print_board(new_board);
                printf("Enter your command: ");
            }
            else{
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
