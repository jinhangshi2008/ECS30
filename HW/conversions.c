#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
/*This program is to convert between the units of temperatures as well as between the units of distances, given the user's choice, the number and unit the user wants to convert, and the unit the user wants to convert to.*/
/*This function is for the conversions between the units of temperatures.*/
void temperaturesUnits(){
    double numA;
    char suffixUnits[50];
    char newUnits[50];
    double numB;
    /*Seperate the user input into two variables for later convinence.*/
    printf("Enter the temperature followed by its suffix (F, C, or K): ");
    scanf("%lf%s", &numA, suffixUnits);
    /*Check the validation of the user inputs.*/
    if(suffixUnits[1] != '\0'){
        printf("Invalid formatting. Ending program.");
        exit(0);
    }
    if(suffixUnits[0] != 'f' && suffixUnits[0] != 'F' && suffixUnits[0] != 'c' && suffixUnits[0] != 'C' && suffixUnits[0] != 'k' && suffixUnits[0] != 'K'){
        printf("%c is not a valid temperature type. Ending program.", suffixUnits[0]);
        exit(0);
    }
    printf("Enter the new unit type (F, C, or K): ");
    scanf(" %s", newUnits);
    if(newUnits[1] != '\0'){
        printf("Invalid formatting. Ending program.");
        exit(0);
    }
    if(newUnits[0] != 'f' && newUnits[0] != 'F' && newUnits[0] != 'c' && newUnits[0] != 'C' && newUnits[0] != 'k' && newUnits[0] != 'K'){
        printf("%c is not a valid temperature type. Ending program.", newUnits[0]);
        exit(0);
    }
    /*Calculation started by matching the units the user's inputs. */
    if(suffixUnits[0] == 'f' || suffixUnits[0] == 'F'){
        if(newUnits[0] == 'F' || newUnits[0] == 'f'){
            numB = numA;
            printf("%.2f%c is %.2f%c", numA, toupper(suffixUnits[0]), numB, toupper(newUnits[0]));
        }
        else if(newUnits[0] == 'c' || newUnits[0] == 'C'){
            numB = (numA - 32);
            numB = numB *5;
            numB = numB /9;
            printf("%.2f%c is %.2f%c", numA, toupper(suffixUnits[0]), numB, toupper(newUnits[0]));
        }
        else if(newUnits[0] == 'k' || newUnits[0] == 'K'){
            numB = (numA - 32)*5;
            numB = numB/9;
            numB = numB + 273.15;
            printf("%.2f%c is %.2f%c", numA, toupper(suffixUnits[0]), numB, toupper(newUnits[0]));
        }
    }
    
    else if(suffixUnits[0] == 'c' || suffixUnits[0] == 'C'){
        if(newUnits[0] == 'c' || newUnits[0] == 'C'){
            numB = numA;
            printf("%.2f%c is %.2f%c", numA, toupper(suffixUnits[0]), numB, toupper(newUnits[0]));
        }
        else if(newUnits[0] == 'f' || newUnits[0] == 'F'){
            numB = numA*9;
            numB = numB/5;
            numB = numB + 32;
            printf("%.2f%c is %.2f%c", numA, toupper(suffixUnits[0]), numB, toupper(newUnits[0]));
        }
        else if(newUnits[0] == 'k' || newUnits[0] == 'K'){
            numB = numA + 273.15;
            printf("%.2f%c is %.2f%c", numA, toupper(suffixUnits[0]), numB, toupper(newUnits[0]));
        }
    }
    
    else if(suffixUnits[0] == 'k' || suffixUnits[0] == 'K'){
        if(newUnits[0] == 'k' || newUnits[0] == 'K'){
            numB = numA;
            printf("%.2f%c is %.2f%c", numA, toupper(suffixUnits[0]), numB, toupper(newUnits[0]));
        }
        else if(newUnits[0] == 'c' || newUnits[0] == 'C'){
            numB = numA - 273.15;
            printf("%.2f%c is %.2f%c", numA, toupper(suffixUnits[0]), numB, toupper(newUnits[0]));
        }
        else if(newUnits[0] == 'f' || newUnits[0] == 'F'){
            numB = (numA - 273.15)*9;
            numB = numB/5;
            numB = numB + 32;
            printf("%.2f%c is %.2f%c", numA, toupper(suffixUnits[0]), numB, toupper(newUnits[0]));
        }
    }
    else{
        printf("%c is not a valid temperature type. Ending program.", suffixUnits[0]);
        exit(0);
    }

}
/*This function is for for the conversions between the units of distances.*/
void distancesUnits(){
    double numC;
    char suffixUnits1[50];
    char newUnits1[50];
    double numD;
    /*Seperate the user input into two variables for later convinence.*/
    /*Check the validation of the user inputs.*/
    printf("Enter the distance followed by its suffix (I,F,Y,M): ");
    if(scanf("%lf", &numC) != 1){
        printf("Invalid formatting. Ending program.");
        exit(0);    
    } 
    scanf("%s", suffixUnits1);
    if(suffixUnits1[1] != '\0'){
        printf("Invalid formatting. Ending program.");
        exit(0);
    }
    if(suffixUnits1[0] != 'i' && suffixUnits1[0] != 'I' && suffixUnits1[0] != 'f' && suffixUnits1[0] != 'F' && suffixUnits1[0] != 'y' && suffixUnits1[0] != 'Y' && suffixUnits1[0] != 'm' && suffixUnits1[0] != 'M'){
        printf("%c is not a valid distance type. Ending program.", suffixUnits1[0]);
        exit(0);
    }
    printf("Enter the new unit type (I,F,Y,M): ");
    scanf(" %s", newUnits1);
    if(newUnits1[1] != '\0'){
        printf("Invalid formatting. Ending program.");
        exit(0);
    }
    if(newUnits1[0] != 'i' && newUnits1[0] != 'I' && newUnits1[0] != 'f' && newUnits1[0] != 'F' && newUnits1[0] != 'y' && newUnits1[0] != 'Y' && newUnits1[0] != 'm' && newUnits1[0] != 'M'){
        printf("%c is not a valid distance type. Ending program.", newUnits1[0]);
        exit(0);
    }
    /*Calculation started by matching the units the user's inputs. */
    if(suffixUnits1[0] == 'i' || suffixUnits1[0] == 'I'){
        if(newUnits1[0] == 'i' || newUnits1[0] == 'I'){
            numD = numC;
            printf("%.2f%c is %.2f%c", numC, toupper(suffixUnits1[0]), numD, toupper(newUnits1[0]));
        }
        else if(newUnits1[0] == 'f' || newUnits1[0] == 'F'){
            numD = numC/12;
            printf("%.2f%c is %.2f%c", numC, toupper(suffixUnits1[0]), numD, toupper(newUnits1[0]));
        }
        else if(newUnits1[0] == 'y' || newUnits1[0] == 'Y'){
            numD = numC/36;
            printf("%.2f%c is %.2f%c", numC, toupper(suffixUnits1[0]), numD, toupper(newUnits1[0]));
        }
        else if(newUnits1[0] == 'm' || newUnits1[0] == 'M'){
            numD = numC/63360;
            printf("%.2f%c is %.2f%c", numC, toupper(suffixUnits1[0]), numD, toupper(newUnits1[0]));
        }
    }
    else if(suffixUnits1[0] == 'f' || suffixUnits1[0] == 'F'){
        if(newUnits1[0] == 'f' || newUnits1[0] == 'F'){
            numD = numC;
            printf("%.2f%c is %.2f%c", numC, toupper(suffixUnits1[0]), numD, toupper(newUnits1[0]));
        }
        else if(newUnits1[0] == 'i' || newUnits1[0] == 'I'){
            numD = numC*12;
            printf("%.2f%c is %.2f%c", numC, toupper(suffixUnits1[0]), numD, toupper(newUnits1[0]));
        }
        else if(newUnits1[0] == 'y' || newUnits1[0] == 'Y'){
            numD = numC/3;
            printf("%.2f%c is %.2f%c", numC, toupper(suffixUnits1[0]), numD, toupper(newUnits1[0]));
        }
        else if(newUnits1[0] == 'm' || newUnits1[0] == 'M'){
            numD = numC/5280;
            printf("%.2f%c is %.2f%c", numC, toupper(suffixUnits1[0]), numD, toupper(newUnits1[0]));
        }
    }
    else if(suffixUnits1[0] == 'y' || suffixUnits1[0] == 'Y'){
        if(newUnits1[0] == 'y' || newUnits1[0] == 'Y'){
            numD = numC;
            printf("%.2f%c is %.2f%c", numC, toupper(suffixUnits1[0]), numD, toupper(newUnits1[0]));
        }
        else if(newUnits1[0] == 'f' || newUnits1[0] == 'F'){
            numD = numC*3;
            printf("%.2f%c is %.2f%c", numC, toupper(suffixUnits1[0]), numD, toupper(newUnits1[0]));
        }
        else if(newUnits1[0] == 'i' || newUnits1[0] == 'I'){
            numD = numC*36;
            printf("%.2f%c is %.2f%c", numC, toupper(suffixUnits1[0]), numD, toupper(newUnits1[0]));
        }
        else if(newUnits1[0] == 'm' || newUnits1[0] == 'M'){
            numD = numC/1760;
            printf("%.2f%c is %.2f%c", numC, toupper(suffixUnits1[0]), numD, toupper(newUnits1[0]));
        }
    }
    else if(suffixUnits1[0] == 'm' || suffixUnits1[0] == 'M'){
        if(newUnits1[0] == 'm' || newUnits1[0] == 'M'){
            numD = numC;
            printf("%.2f%c is %.2f%c", numC, toupper(suffixUnits1[0]), numD, toupper(newUnits1[0]));
        }
        else if(newUnits1[0] == 'i' || newUnits1[0] == 'I'){
            numD = numC*63360;
            printf("%.2f%c is %.2f%c", numC, toupper(suffixUnits1[0]), numD, toupper(newUnits1[0]));
        }
        else if(newUnits1[0] == 'y' || newUnits1[0] == 'Y'){
            numD = numC*1760;
            printf("%.2f%c is %.2f%c", numC, toupper(suffixUnits1[0]), numD, toupper(newUnits1[0]));
        }
        else if(newUnits1[0] == 'f' || newUnits1[0] == 'F'){
            numD = numC*5280;
            printf("%.2f%c is %.2f%c", numC, toupper(suffixUnits1[0]), numD, toupper(newUnits1[0]));
        }
    }
}
/*This function is for the user to decide the field of units that is wanted to be converted.*/
void choicesDecide(){
    char choices[50];
    printf("Pick the type of conversion that you would like to do.\n");
    printf("T or t for temperature\n");
    printf("D or d for distance\n");
    printf("Enter your choice: ");
    scanf("%s", choices);
    
    if(choices[1] != '\0'){
        printf("Invalid formatting. Ending program.");
        exit(0);
    }

    if(choices[0] == 't' || choices[0] == 'T'){
        temperaturesUnits();
    }
    else if(choices[0] == 'D' || choices[0] == 'd'){
        distancesUnits();
    }
    else if((choices[0] >= 'A' && choices[0] <= 'C') || (choices[0] >= 'E' && choices[0] <= 'S') || (choices[0] >= 'U' && choices[0] <= 'Z') || (choices[0] >= 'a' && choices[0] <= 'c') || (choices[0] >= 'e' && choices[0] <= 's') ||   (choices[0] >= 'u' && choices[0] <= 'z')){
        printf("Unknown conversion type %c chosen. Ending Program.", choices[0]);
        exit(0);
    }


}
/*The program runs in this function*/
int main(){
    choicesDecide();
}
