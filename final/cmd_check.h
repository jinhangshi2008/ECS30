#ifndef CMD_CHECK1_H
	#define CMD_CHECK1_H
	#include <stdio.h>
    #include <stdlib.h>
    #include "board.h"
    #include <ctype.h>
    int cmd_rows(int argc, char* argv[]);
    int cmd_cols(int argc, char* argv[]);
    void cmd_check(int argc, char* argv[], Board* board1);
#endif