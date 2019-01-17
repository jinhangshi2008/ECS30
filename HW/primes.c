#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
/*this program is to list all the prime numbers from 2 to a number larger or equal to 2.*/
//check if the format of the input is valid
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
//keep asking for input if the format is wrong
int get_valid(){
	int num1;
	int num_args_read;
	do{
		printf("Enter a number greater than 1: ");
		num_args_read = scanf("%d", &num1);
	}while(!(is_valid_formatting(num_args_read, 1))||num1 <= 1);
	
	return num1;
}
//this function calculates how large the space should be for an array
int space(int num1){
    int* prime3;
    int i, j, n;
    prime3 = (int*)malloc((num1+1)*sizeof(int));
    j = 0;
    //initialize with all the numbers listed
    for(i=0;i<=num1;i++){
      prime3[i] = i;
   }
   //set the numbers which are not prime to 0
    for(i=2;i<=num1;i++){
        for(n=2;n<i;n++){
        if(i % n == 0){
        prime3[i] = 0;
        break;
        }
        }
        //if the number is prime, count it
        if(prime3[i] != 0){
                j++;
           }
    }
    free(prime3);
    return j;
}
//this function sets up the array which will be printed out
int* prime(int num1){
    int* prime1;
    int* prime2;
    int i, j, n, B;
    B = space(num1);
    j = 0;
    prime1 = (int*)malloc((num1+1)*sizeof(int));
    prime2 = (int*)malloc((B+1)*sizeof(int));
    //initialize with all the numbers listed
    for(i=0;i<=num1;i++){
      prime1[i] = i;
   }
   //set the numbers which are not prime to 0
    for(i=2;i<=num1;i++){
        for(n=2;n<i;n++){
        if(i % n == 0){
        prime1[i] = 0;
        break;
        }
        }
         //if the number is prime, copy it to the second array and move to the next position in that array
        if(prime1[i] != 0){
                prime2[j] = prime1[i];
                j++;
           }
    }
    free(prime1);
    free(prime2);
    prime2[0] = 2;
    return prime2;
}
//print out the prime numbers
void process(int num1){
int* A;
int B, i;
A = prime(num1);
B = space(num1);
for(i=0;i<B;i++){
    printf("%d\n", A[i]);
}
}
int main(){
    int num1;
    num1 = get_valid();
    printf("The primes between 2 and %d are: \n", num1);
    process(num1);
    return 0;
}