#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<stdbool.h>
/*This program is to calculate what the average rounds it takes for two points to get together from two spots on a R X C board.*/
/*This part is for input format checking.*/
bool is_valid_formatting(int num_args_read, int num_args_needed){
	char new_line = '\n';
	bool is_valid = true; 
	if(num_args_read != num_args_needed){ 
		is_valid = false;
	}
	do{
		scanf("%c", &new_line);
		if(!isspace(new_line)){ 
			is_valid = false;
		}
	}while(new_line != '\n'); 
	return is_valid;
}
/*4 functions below will keep asking the users for valid format input.*/
int valid_seed(){
	int seed;
	int num_args_read;
	do{
		printf("Enter the seed for the random number generator: ");
		num_args_read = scanf("%d", &seed);
	}while(!(is_valid_formatting(num_args_read, 1)));
	return seed;
}
int valid_rows(){
	int rows;
	int num_args_read;
	do{
		printf("Enter the number of rows on the board: ");
		num_args_read = scanf("%d", &rows);
	}while(!(is_valid_formatting(num_args_read, 1))||rows<=0);
	
	return rows;
}
int valid_cols(){
	int cols;
	int num_args_read;
	do{
		printf("Enter the number of columns on the board: ");
		num_args_read = scanf("%d", &cols);
	}while(!(is_valid_formatting(num_args_read, 1))||cols<=0);
	
	return cols;
}
int valid_sim(){
	int sim;
	int num_args_read;
	do{
		printf("Enter the number of simulations to run: ");
		num_args_read = scanf("%d", &sim);
	}while(!(is_valid_formatting(num_args_read, 1))||sim<=0);
	
	return sim;
}
/*This function represents the formula for the row or the column of one point moves from the old ones to the new ones.*/
int move(int start, int end){
    if(start < end){
        return start + rand() % (end - start + 1);/*Plus one here gives us wider range of numbers.*/
    }
    else if(start > end){
        return start - rand() % (start - end + 1);
    }
    else{
        return start;
    }
}
/*Check if the two points are at the same position.*/
bool same(int row1, int col1, int row2, int col2){
    return row1 == row2 && col1 == col2;
}
/*This part simulates the movement of these two points until they get together. And return the number of rounds it takes in the end.*/
int run_meetup(int row1, int col1, int row2, int col2, int numSim){
    int numRounds = 0;
    int newRow1, newCol1, newRow2, newCol2;
    while(!same(row1, col1, row2, col2)){
        
        newRow1 = move(row1, row2);
        newCol1 = move(col1, col2);
        newRow2 = move(row2, row1);
        newCol2 = move(col2, col1);
        /*If the number of simulation is too large. We skip printing the steps.*/
        if(numSim < 100){
        printf("First piece moves from %d,%d to %d,%d\n", row1, col1, newRow1, newCol1);
        printf("Second piece moves from %d,%d to %d,%d\n", row2, col2, newRow2, newCol2);
        }
        row1 = newRow1;
        row2 = newRow2;
        col1 = newCol1;
        col2 = newCol2;
        numRounds++;

    }
    return numRounds;
}
/*This part simulates the movement of these two points on the R X C board. And return the average rounds it takes in the end.*/
double run_sim(int numRows, int numCols, int numSim){
    int i;
    int row1, col1, row2, col2;
    int totalRounds = 0;
    for(i=0;i<numSim;i++){
        row1 = rand() % numRows;
        col1 = rand() % numCols;
        row2 = rand() % numRows;
        col2 = rand() % numCols;
        /*If the number of simulation is too large. We skip printing the steps.*/
        if(numSim < 100){
        printf("Simulation %d\n\n", i);
        printf("Piece one starts at: %d, %d\n", row1, col1);
        printf("Piece two starts at: %d, %d\n", row2, col2);
        }
        totalRounds += run_meetup(row1, col1, row2, col2, numSim);
    }
    return (double) totalRounds / (double) numSim;
}
void input(){
    double avgRounds;
    int A, B, C, D;
    A = valid_seed();
    B = valid_rows();
    C = valid_cols();
    D = valid_sim();
    srand(A);
    avgRounds = run_sim(B, C, D);
    printf("On average it takes %.2f rounds on a board %d X %d for the pieces to meet.\n", avgRounds, B, C);
}
int main(){
    input();
    return 0;
}