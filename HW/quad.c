#include<stdio.h>
#include<math.h>
/*This program is to calculate the roots of a quadratic function, given numA, numB, and numC.*/
void divide(){
    /*Define the variables in this calculation.*/
    double numA = 0.0;
    double numB = 0.0;
    double numC = 0.0;
    double numX1 = 0.0;
    double numX2 = 0.0;
     /*This part checks if the a in the quadratic function is zero. The program will not continue until the user enters an non-zero number.*/
     do{
        printf("Please enter a: ");
        scanf("%lf", &numA);
    }while(numA == 0);
    
     printf("Please enter b: ");
    scanf("%lf", &numB);
    printf("Please enter c: ");
    scanf("%lf", &numC);
    /*This part divides the results into two situations. One for having real solutions and another for having no real solutions.*/
    numX1 = (-numB + sqrt(numB*numB - 4*numA*numC))/(2*numA);
    numX2 = (-numB - sqrt(numB*numB - 4*numA*numC))/(2*numA);
    
    if(sqrt(numB*numB - 4*numA*numC) >= 0) {
    /*This part divides having real solutions into two situations. One for having one real solution and another for having two real solutions.*/
    if(numX1 == numX2){
        printf("There is one real solution: %.2f", numX1);
    }
    else{
        printf("There are 2 real solutions \n");
        printf("Solution 1: %.2f\n", numX1);
        printf("Solution 2: %.2f\n", numX2);
    }
    }
    else{
        printf("There are no real solutions");
}

}
int main(){
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    divide();
    
}