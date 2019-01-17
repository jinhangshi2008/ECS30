#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <stdbool.h>
/*This program is to determine if it is better to put as much money as you can
towards your student loans before saving for retirement or if it is better to only pay the
minimum payment on your loan and invest the rest.*/
/*Check if format is valid for each input. If not, the program continues to ask.*/
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
/*These 7 functions keeps asking user's input if the input is invalid. Once they are valid, the functions return the value of those inputs*/
double get_valid1(){     
    double howmuch;
    int num_args_read;
    do{
		printf("Enter how much money you will be putting towards loans/retirement each month: ");
		num_args_read = scanf("%lf", &howmuch);
	}while(!(is_valid_formatting(num_args_read, 1))||howmuch <= 0);
	
	return howmuch;
}
double get_valid2(){     
    double owe;
    int num_args_read;
    do{
		printf("Enter how much you owe in loans: ");
		num_args_read = scanf(" %lf", &owe);
	}while(!(is_valid_formatting(num_args_read, 1))||owe <= 0);
	
	return owe;
}
double get_valid3(){     
    double annualRate;
    int num_args_read;
    do{
		printf("Enter the annual interest rate of the loans: ");
		num_args_read = scanf(" %lf", &annualRate);
	}while(!(is_valid_formatting(num_args_read, 1))||annualRate <= 0);
	
	return annualRate;
}
double get_valid4(){     
    double minLoan;
    int num_args_read;
    do{
		printf("Enter your minimum monthly loan payment: ");
		num_args_read = scanf(" %lf", &minLoan);
	}while(!(is_valid_formatting(num_args_read, 1))||minLoan <= 0);
	
	return minLoan;
}
double get_valid5(){     
    double currentAge;
    int num_args_read;
    do{
		printf("Enter your current age: ");
		num_args_read = scanf(" %lf", &currentAge);
	}while(!(is_valid_formatting(num_args_read, 1))||currentAge <= 0);
	
	return currentAge;
}
double get_valid6(){     
    double retireAge;
    int num_args_read;
    do{
		printf("Enter the age you plan to retire at: ");
		num_args_read = scanf(" %lf", &retireAge);
	}while(!(is_valid_formatting(num_args_read, 1))||retireAge <= 0);
	
	return retireAge;
}
double get_valid7(){     
    double annualReturn;
    int num_args_read;
    do{
		printf("Enter the annual rate of return you predict for your investments: ");
		num_args_read = scanf(" %lf", &annualReturn);
	}while(!(is_valid_formatting(num_args_read, 1))||annualReturn <= 0);
	
	return annualReturn;
}
/*This function calculates how much you will get in the end when you pay your loan as much as you can before any savings.*/
double calc_asmuch(double howmuch, double owe, double annualRate, double currentAge, double retireAge, double annualReturn){
    double monthRate1, monthRate2;
    int i = 0;
    double Get;
    monthRate1 = annualRate/12;
    monthRate2 = annualReturn/12;
        for(i = 1; i <= 12*(retireAge - currentAge); ++i){
            if(owe > 0){
                owe = (1 + monthRate1) * owe;
                owe = owe - howmuch;
                if(owe < 0){
                    Get = -owe;
                }
            }
        else{
            Get = (1 + monthRate2) * Get;
            Get = Get + howmuch;
        }
        }
        return Get;
    }
/*This function calculates how much you will get in the end when you only pay the minimum loan monthly while making savings.*/
double calc_min(double howmuch, double owe, double annualRate, double minLoan, double currentAge, double retireAge, double annualReturn){
    double monthRate1, monthRate2;
    int i = 0;
    double Get1 = 0;
    monthRate1 = annualRate/12;
    monthRate2 = annualReturn/12;
    for(i = 1; i <= 12*(retireAge - currentAge); ++i){
        if(owe > 0){
            owe = (1 + monthRate1) * owe;
            owe = owe - minLoan;
            Get1 = (1 + monthRate2) * Get1;
            if(owe < 0){
                Get1 = (-owe) + Get1 + (howmuch - minLoan);
            }
            else{
            Get1 = Get1 + (howmuch - minLoan);
            }
        }   
    else{
        Get1 = (1 + monthRate2) * Get1;
        Get1 = Get1 + howmuch;
    }
    }
    /*If the loan is not paid completely in the end, the program will warn the users.*/
    if(owe > 0){
        printf("Warning! After you retire you will still have $%.2lf in loans left.\n", owe);
    }
    return Get1;
}
/*This function gathers all the functions above to compare which way is better based on the users' inputs.*/
void input(){   
    double E, F, G, H, I, J, K, X, Y;
    E = get_valid1();  /*howmuch*/
    F = get_valid2();  /*owe*/
    G = get_valid3();  /*annualRate*/
    H = get_valid4();  /*minLoan*/
    /*If the user puts minimum loan per month higher than how much the user can pay per month, the program will end.*/
    if(E < H*(1 + (G/12))){
        printf("You didn't set aside enough money to pay off our loans. Ending program.");
        exit(0);
    }
    I = get_valid5();  /*currentAge*/
    /*If the user puts a retire age smaller than current age, the program will keep ask the user.*/
    do{ 
    J = get_valid6();  /*retireAge*/
     }while(J < I);
    K = get_valid7();  /*annualReturn*/
    X = calc_asmuch(E, F, G, I, J, K);
    Y = calc_min(E, F, G, H, I, J, K);
    if(X > Y){
        printf("You should apply all $%.2lf towards your loan before making any investments.\n", E);
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you only made minimum payments.", X, Y);
    }
    else if(X < Y){
        printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you payed off your loan before investing.", Y, X);
    }
}
int main(){
    input();
    return 0;
}