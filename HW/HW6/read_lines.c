#include "read_lines.h"
//This function read a file line by line
void read_lines(FILE* fp, char*** lines, int* num_lines){
    *num_lines = 0;
    int num_char = 0;
    int* str_num_char;
    char c;
    int i, j, k;
    //if the file is empty, set everything to default and end the program
    if(fp == NULL){
        *lines = NULL;
        *num_lines = 0;
        exit(0);
    }
    //begin reading file and count lines
    while(!feof(fp)){
        fscanf(fp, "%c", &c);
        if(c == '\n'){
            (*num_lines)++;
        }
    }
   
    (*num_lines)--;
    //go back to the begining of the file
    fseek(fp, 0, SEEK_SET);
    //dynamically allocate memory for a pointer which record the number of characters in each line
    str_num_char = (int*)malloc((*num_lines) * sizeof(int));
     k = 0;
     //count the characters in each line
    while(!feof(fp)){
        fscanf(fp, "%c", &c);
        num_char++;
        if(c == '\n'){
            str_num_char[k] = num_char;
            k++;
            num_char = 0;
        }
    }
    fseek(fp, 0, SEEK_SET);
    //fill in the characters
    *lines = (char**) malloc(((*num_lines)) * sizeof(char*));
    for(i=0;i<*num_lines;i++){
        (*lines)[i] = (char*) malloc((str_num_char[i] + 1) *sizeof(char));
        for(j=0;j < str_num_char[i]; j++){
                fscanf(fp, "%c", &c);
                (*lines)[i][j] = c;
        }
        (*lines)[i][j] = '\0';
    }
    free(str_num_char);
}
