#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
/*This program is to calculate the percent needed from right now for an ECS30 student to get the grade level he or she wants, given the grade level the student wants, the total percent needed to get that grade, the current percent 
the student has, and the weight of the final */
void calculate(){
    /*Define the variables in this calculation.*/
    char gradeLevel[50];
    char test;
    double percentCurrent = 0.0;
    double finalWeight;
    double finalNeed = 0.0;
    /*User inputs grade level wanted.*/
    printf("Enter the grade you want in the class: ");
    scanf("%s", gradeLevel);
    /*This part crosses out the wrong input for grade level.*/
    if(gradeLevel[1] != '\0'){
        printf("Invalid formatting. Ending program.");
        exit(0);
    }
    else if(gradeLevel[0] >= 'G' && gradeLevel[0] <= 'Z' ){
        printf("Unknown Grade Received: %c. Ending program.", gradeLevel[0]);
        exit(0);
    }
    else if(gradeLevel[0] >= 'g' && gradeLevel[0] <= 'z' ){
        printf("Unknown Grade Received: %c. Ending program.", gradeLevel[0]);
        exit(0);
    }

    else if(gradeLevel[0] == 'E'){
        printf("Unknown Grade Received: %c. Ending program.", gradeLevel[0]);
        exit(0);
    }
    else if(gradeLevel[0] == 'e'){
        printf("Unknown Grade Received: %c. Ending program.", gradeLevel[0]);
        exit(0);
    }
    /*This part crosses out the wrong input for current percent.*/
    printf("Enter your current percent in the class: ");
    if(scanf("%lf", &percentCurrent) != 1){
        printf("Invalid formatting. Ending program.");
        exit(0);
        }
    else if(percentCurrent < 0){
        printf("The number you last entered should have been positive. Ending program.");
        exit(0);
    }
    /*This part crosses out the wrong input for the weight of the final.*/
    printf("Enter the weight of the final: ");
    if(scanf("%lf", &finalWeight) != 1){
        printf("Invalid formatting. Ending program.");
        exit(0);
    }
    else if(finalWeight < 0){
        printf("The number you last entered should have been positive. Ending program.");
        exit(0);
    }
     
    scanf("%c",&test);
    if(test != '\n'){
        printf("Invalid formatting. Ending program.");
        exit(0);
    }
    /*This part calculates the final percent needed for grade A(a), B(b), C(c), D(d), F(f), as well as the summary for getting those grades.*/
    if(gradeLevel[0] == 'A'){
        finalNeed = (((90 - (percentCurrent*(1-(finalWeight*0.01))))/(finalWeight)))*100;
        if(finalNeed > 100){
            printf("You cannot get a %c in the class because you would need to score at least %.2f%% on the final.", gradeLevel[0], finalNeed);
        }
        else if((percentCurrent*(1-(finalWeight*0.01))) >= 90){
            printf("You cannot score low enough on the final to get a %c in the class.", gradeLevel[0]);
        }   
        else{
            printf("You need a grade of at least %.2f%% on the final to get a %c in the class.", finalNeed, gradeLevel[0]);
    }}
    else if(gradeLevel[0] == 'a'){
        finalNeed = (((90 - (percentCurrent*(1-(finalWeight*0.01))))/(finalWeight)))*100;
        if(finalNeed > 100){
            printf("You cannot get a %c in the class because you would need to score at least %.2f%% on the final.", gradeLevel[0], finalNeed);
        }
        else if((percentCurrent*(1-(finalWeight*0.01))) >= 90){
            printf("You cannot score low enough on the final to get a %c in the class.", gradeLevel[0]);
        }
        else{
            printf("You need a grade of at least %.2f%% on the final to get a %c in the class.", finalNeed, gradeLevel[0]);
    }}    
    
    else if(gradeLevel[0] == 'B'){
        finalNeed = (((80 - (percentCurrent*(1-(finalWeight*0.01))))/(finalWeight)))*100;
        if(finalNeed > 100){
            printf("You cannot get a %c in the class because you would need to score at least %.2f%% on the final.", gradeLevel[0], finalNeed);
        }
        else if((percentCurrent*(1-(finalWeight*0.01))) >= 80){
            printf("You cannot score low enough on the final to get a %c in the class.", gradeLevel[0]);
        }
        else{
            printf("You need a grade of at least %.2f%% on the final to get a %c in the class.", finalNeed, gradeLevel[0]);
    }}
    else if(gradeLevel[0] == 'b'){
        finalNeed = (((80 - (percentCurrent*(1-(finalWeight*0.01))))/(finalWeight)))*100;
        if(finalNeed > 100){
            printf("You cannot get a %c in the class because you would need to score at least %.2f%% on the final.", gradeLevel[0], finalNeed);
        }
        else if((percentCurrent*(1-(finalWeight*0.01))) >= 80){
            printf("You cannot score low enough on the final to get a %c in the class.", gradeLevel[0]);
        }
        else{
            printf("You need a grade of at least %.2f%% on the final to get a %c in the class.", finalNeed, gradeLevel[0]);
    }}
        

    else if(gradeLevel[0] == 'C'){
        finalNeed = (((70 - (percentCurrent*(1-(finalWeight*0.01))))/(finalWeight)))*100;
        if(finalNeed > 100){
            printf("You cannot get a %c in the class because you would need to score at least %.2f%% on the final.", gradeLevel[0], finalNeed);
        }
        else if((percentCurrent*(1-(finalWeight*0.01))) >= 70){
            printf("You cannot score low enough on the final to get a %c in the class.", gradeLevel[0]);
        }
        else{
            printf("You need a grade of at least %.2f%% on the final to get a %c in the class.", finalNeed, gradeLevel[0]);
    }}
    else if(gradeLevel[0] == 'c'){
        finalNeed = (((70 - (percentCurrent*(1-(finalWeight*0.01))))/(finalWeight)))*100;
        if(finalNeed > 100){
            printf("You cannot get a %c in the class because you would need to score at least %.2f%% on the final.", gradeLevel[0], finalNeed);
        }
        else if((percentCurrent*(1-(finalWeight*0.01))) >= 70){
            printf("You cannot score low enough on the final to get a %c in the class.", gradeLevel[0]);
        }
        else{
            printf("You need a grade of at least %.2f%% on the final to get a %c in the class.", finalNeed, gradeLevel[0]);
    }}   
    else if(gradeLevel[0] == 'D'){
        finalNeed = (((60 - (percentCurrent*(1-(finalWeight*0.01))))/(finalWeight)))*100;
        if(finalNeed > 100){
            printf("You cannot get a %c in the class because you would need to score at least %.2f%% on the final.", gradeLevel[0], finalNeed);
        }
        else if((percentCurrent*(1-(finalWeight*0.01))) >= 60){
            printf("You cannot score low enough on the final to get a %c in the class.", gradeLevel[0]);
        }
        else{
            printf("You need a grade of at least %.2f%% on the final to get a %c in the class.", finalNeed, gradeLevel[0]);
    }}
    else if(gradeLevel[0] == 'd'){
        finalNeed = (((60 - (percentCurrent*(1-(finalWeight*0.01))))/(finalWeight)))*100;
        if(finalNeed > 100){
            printf("You cannot get a %c in the class because you would need to score at least %.2f%% on the final.", gradeLevel[0], finalNeed);
        }
        else if((percentCurrent*(1-(finalWeight*0.01))) >= 60){
            printf("You cannot score low enough on the final to get a %c in the class.", gradeLevel[0]);
        }
        else{
            printf("You need a grade of at least %.2f%% on the final to get a %c in the class.", finalNeed, gradeLevel[0]);
    }}    

    else if(gradeLevel[0] == 'F'){
        finalNeed = (((0 - (percentCurrent*(1-(finalWeight*0.01))))/(finalWeight)))*100;
        if(finalNeed > 100){
            printf("You cannot get a %c in the class because you would need to score at least %.2f%% on the final.", gradeLevel[0], finalNeed);
        }
        else if((percentCurrent*(1-(finalWeight*0.01))) > 0){
            printf("You cannot score low enough on the final to get a %c in the class.", gradeLevel[0]);
        }
        else{
            printf("You need a grade of at least %.2f%% on the final to get a %c in the class.", finalNeed, gradeLevel[0]);
    }}

     else if(gradeLevel[0] == 'f'){
        finalNeed = (((0 - (percentCurrent*(1-(finalWeight*0.01))))/(finalWeight)))*100;
        if(finalNeed > 100){
            printf("You cannot get a %c in the class because you would need to score at least %.2f%% on the final.", gradeLevel[0], finalNeed);
        }
        else if((percentCurrent*(1-(finalWeight*0.01))) > 0){
            printf("You cannot score low enough on the final to get a %c in the class.", gradeLevel[0]);
        }
        else{
            printf("You need a grade of at least %.2f%% on the final to get a %c in the class.", finalNeed, gradeLevel[0]);
    }}
}
int main(){
    calculate();
}   