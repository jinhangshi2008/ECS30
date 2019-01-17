#include <stdio.h>
#include <stdlib.h>
/*This program is to ask the user for 2 matrices A, and B, and
displays their sum, C.*/
/*First, ask the user for matrix A.*/
int** matrixA(int rows, int cols){
    int** matrix;
    int i, j;
    printf("Enter Matrix A \n");
    /*malloc allocates dynamically allocated rows.*/
    matrix = (int**)malloc(rows*sizeof(int*));
  /*In each row, allocates dynamically allocated columns.*/
  for(i =0; i < rows; i++){
    matrix[i] = (int*)malloc(cols*sizeof(int));
  }
  /*Now ask user for the input.*/
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
        scanf("%d ", &matrix[i][j]);
        }
    }
    return matrix;
}
/*This part asks the user for matrix B.*/
int** matrixB(int rows, int cols){
    int** matrix1;
    int i, j;
    printf("Enter Matrix B \n");
matrix1 = (int**)malloc(rows*sizeof(int*));
  
  for(i =0; i < rows; i++){
    matrix1[i] = (int*)malloc(cols*sizeof(int));
  }
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
        scanf("%d ", &matrix1[i][j]);
        }
    }
    return matrix1;
}
/*On this step, we add the numbers in each matrix on the same positions.*/
void sum(int rows, int cols){
    int i, j;
    int** A;
    int** B;
    A = matrixA(rows, cols);
    B = matrixB(rows, cols);
    printf("A + B = \n");
/*By using two for loops, we add the numbers on the same positions one by one.*/
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
        printf("%d ", (A[i][j]) + (B[i][j]));
        }
        printf("\n");
    }
}
int main(){
    int rows, cols;
    printf("Please enter the number of rows: ");
    scanf("%d", &rows);
    printf("Please enter the number of columns: ");
    scanf("%d", &cols);
    sum(rows, cols);
    return 0; 

}