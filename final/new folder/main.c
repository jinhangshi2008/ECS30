#include <stdio.h>
#include "board.h"
#include "cmd_check.h"
#include "test.h"

int main(int argc, char* argv[]){
    Board board;
    cmd_check(argc, argv, &board);
    input_identify(board);
    clean_up(board);
    return 0;
}