#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <ctype.h>
#include <stdbool.h>
/*This program is to calculate pi by determing how many random points lay in a circle of radius 1 while the circle is in a square of 1 X 1.*/
/*First get random coordinates for X and Y.*/
double rand_X(double LO, double HI){
    return (LO + ((double) (rand()) /(((double) RAND_MAX)/(HI-LO))));
}
double rand_Y(double low, double high){
    return (low + ((double) rand()) /(((double) RAND_MAX)/(high-low)));
}
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
/*If the user enters invalid input, the program continues to ask.*/
int get_valid(){
	int seed;
	int num_args_read;
	do{
		printf("Enter the seed for the random number generator: ");
		num_args_read = scanf("%d", &seed);
	}while(!(is_valid_formatting(num_args_read, 1)));
	
	return seed;
}
int getValid(){
    int iteration;
    int num_args_read;
    do{
    printf("Enter the number of iterations to run: ");
    num_args_read = scanf("%d", &iteration);
    }while(!(is_valid_formatting(num_args_read, 1))||(iteration <= 0));
    return iteration;
}
void input(){
int i;
int inCircle = 0;
double pi;
int x, y;
x = get_valid();
y = getValid();
srand(x);
/*This loop counts how many points lay in the circle.*/   
for(i=0;i<y;++i){
if(sqrt(pow(rand_X(-1.0, 1.0),2) + pow(rand_Y(-1.0, 1.0),2)) <= 1){
    inCircle = inCircle + 1;
}
}
pi = ((double)inCircle/(double)y)*4;
printf("The value of pi is %.5f.", pi);
}
int main(){
    input();
    return 0;
}