#include<stdio.h>
/*This programs is to calculate the multiplication of two complex numbers, given two complex numbers.*/
int main(){
    /*Define the variables in this calculation.*/
    int numA1 = 0;/*Define numA1 as the a of the first complex number ai+b.*/
    int numB1 = 0;/*Define numB1 as the b of the first complex number ai+b.*/
    int numA2 = 0;/*Define numA2 as the a of the second complex number ai+b.*/
    int numB2 = 0;/*Define numB2 as the b of the second complex number ai+b.*/
    /*Ask the user for information that should be given for calculation.*/
    printf("Enter the first complex number in the form ai + b: ");/*Ask the user for the input of the first complex number.*/
    scanf("%d i + %d", &numA1, &numB1);/*The input of the first complex number user enters.*/
    printf("Enter the second complex number in the form ai + b: ");/*Ask the user for the input of the second complex number.*/
    scanf("%d i + %d", &numA2, &numB2);/*The input of the second complex number user enters.*/
    /*Output the whole process of the calculation.*/
    printf("(%di + %d) * (%di + %d) = %di + %d ", numA1, numB1, numA2, numB2, ((numA1*numB2)+(numA2*numB1)), ((numB1*numB2)-(numA1*numA2)));/*Calculation of multiplying the two complex numbers user enters.*/
return 0;
}
