#include<stdio.h>
#include<math.h>
/*This program is to calculate the total amount of payment for the loan and the cost of the loan, given the principal, annual interest rate, and number of payment.*/
int main(){
    /*Define the variables in this calculation.*/
    double principal = 0.0;/*The amount of principal.*/
    double interestRate = 0.0;/*The annual interest rate.*/
    int numPayment = 0;/*The number of payment.*/
    double payment = 0.0;/*The total amount of payment.*/
    double loanCost = 0.0;/*The cost of the loan.*/
    double numPow = 0.0;/*Part of the formula for calculating the amount of payment.*/
    /*Ask the user for information that should be given for calculation.*/
    printf("Please enter the amount of money you borrowed: ");
    scanf("%lf", &principal);
    printf("$Please enter the annual interest rate: ");
    scanf("%lf", &interestRate);
    printf("Please enter the number of payments to be made: ");
    scanf("%d", &numPayment);
    /*The calculation of the total amount of payment and the cost of the loan.*/
    numPow = pow((1 + (interestRate/12)), -numPayment);
    payment = ((interestRate/12) * principal)/(1 - numPow);
    loanCost = payment * numPayment - principal;
    /*Summary of the result of the calculation.*/
    printf("A loan of $%.2f with an annual interest of %.2f payed off ", principal, interestRate);/**/
    printf("over %d months will have monthly payments of $%.2f. \n", numPayment, payment);/**/
    printf("In total you will pay $%.2f, making the cost of your loan $%.2f. ",  numPayment * payment, loanCost);/**/
return 0;
}