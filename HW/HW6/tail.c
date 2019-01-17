#include <stdio.h>
#include <stdlib.h>
void print_lines(char** lines, int num_lines, int last_lines){
	int i;
	//if the last lines to be printed is larger than the number of lines, it will just printf out the whole file
	if(last_lines >= num_lines){
		for(i = 0;i < num_lines;++i){
		printf("%s", lines[i]);
	}
	}
	else{
	for(i = num_lines - last_lines;i < num_lines;++i){
		printf("%s", lines[i]);
	}
	}
}
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
    if(*num_lines == 0){
        *num_lines = 1;
    }
    (*num_lines)--;
    //go back to the begining of the file
    fseek(fp, 0, SEEK_SET);
    //dynamically allocate memory for a pointer which record the number of characters in each line
    str_num_char = (int*)malloc(((*num_lines)+1) * sizeof(int));
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
    *lines = (char**) malloc(((*num_lines)+1) * sizeof(char*));
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

void free_lines(char** lines, int num_lines){
	int i;
	
	for(i = 0 ; i < num_lines; ++i){
		free(lines[i]);
	}
	
	if(lines != NULL && num_lines > 0){
		free(lines);
	}

}
FILE* validate_input1(int argc, char* argv[]){

	FILE* fp = NULL;
//three arguments are needed include tail.out
	if(argc < 3){
		printf("Not enough arguments entered.\nEnding program.\n");
		exit(0);
	}
	else if(argc > 3){
		printf("Too many arguments entered.\nEnding program.\n");
		exit(0);
	}
	
	fp = fopen(argv[1], "r");
	
	if(fp == NULL){
		printf("Unable to open file: %s\nEnding program.\n", argv[1]);
		exit(0);
	}
	
	return fp;

}
void last_line(char* argv[], int* last_lines){
    sscanf(argv[2] ,"%d", &(*last_lines));
}
int main(int argc, char *argv[]){
    int last_lines = 0;
	int num_lines = 0;
	char** lines = NULL;
    FILE* fp = validate_input1(argc, argv);
    last_line(argv, &last_lines);
	read_lines(fp, &lines, &num_lines);
	print_lines(lines, num_lines, last_lines);
	free_lines(lines, num_lines);
	fclose(fp);
}