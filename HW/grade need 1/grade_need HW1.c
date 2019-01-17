#include<stdio.h>
/*This program is to calculate the percent needed from right now for an ECS30 student to get the grade level he or she wants, given the grade level the student wants, the total percent needed to get that grade, the current percent 
the student has, and the weight of the final */
int main(){
    /*Define the variables in this calculation.*/
    char gradeLevel = '?';/*The grade level the student wants.*/
    double percentNeed = 0.0;/*The total percent needed for the student to get that grade.*/
    double percentCurrent = 0.0;/*The current percent the student has.*/
    double finalWeight = 0.0;/*The weight of the final.*/
    double finalNeed = 0.0; /*The percent the student needs to get that grade*/
    /*Ask the user for information that should be given for calculation.*/
    printf("Enter the grade you want in the class: ");/*Ask for the grade level the student wants.*/
    scanf("%c", &gradeLevel);/*The input of the grade level the user enters.*/
    printf("Enter the percent in the class you need in the class to get that grade: ");/*Ask for the total percent needed for getting that grade.*/
    scanf("%lf", &percentNeed);/*The input of the percent needed the user enters.*/
    printf("Enter your current percent in the class: ");/*Ask for the current percent the student has.*/
    scanf("%lf", &percentCurrent);/*The input of the current percent the user enters.*/
    printf("Enter the weight of the final: ");/*Ask for the weight of the final.*/
    scanf("%lf", &finalWeight);/*The input of the weight of the final the user enters.*/
    /*The calculation of the percent needed to get on final*/
    finalNeed = (((percentNeed - (percentCurrent*(1-(finalWeight*0.01))))/(finalWeight)))*100;/*Calculation for the percent the student needs on final to get that grade.*/
    /*The conclusion of how many percent the student needs to get on the final to get that grade.*/
    printf("You need to get at least %.2f%% on the final to get a %c in the class. ", finalNeed, gradeLevel);/*Conclusion on the percent the student needs to get on final.*/
    return 0;

}