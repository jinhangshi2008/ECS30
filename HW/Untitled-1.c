#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <stdbool.h>
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
		num_args_read = scanf("%lf", &owe);
	}while(!(is_valid_formatting(num_args_read, 1))||owe <= 0);
	
	return owe;
}
double get_valid3(){     
    double annualRate;
    int num_args_read;
    do{
		printf("Enter the annual interest rate of the loans: ");
		num_args_read = scanf("%lf", &annualRate);
	}while(!(is_valid_formatting(num_args_read, 1))||annualRate <= 0);
	
	return annualRate;
}
double get_valid4(){     
    double minLoan;
    int num_args_read;
    do{
		printf("Enter your minimum monthly loan payment: ");
		num_args_read = scanf("%lf", &minLoan);
	}while(!(is_valid_formatting(num_args_read, 1))||minLoan <= 0);
	
	return minLoan;
}
double get_valid5(){     
    double currentAge;
    int num_args_read;
    do{
		printf("Enter your current age: ");
		num_args_read = scanf("%lf", &currentAge);
	}while(!(is_valid_formatting(num_args_read, 1))||currentAge <= 0);
	
	return currentAge;
}
double get_valid6(){     
    double retireAge;
    int num_args_read;
    do{
		printf("Enter the age you plan to retire at: ");
		num_args_read = scanf("%lf", &retireAge);
	}while(!(is_valid_formatting(num_args_read, 1))||retireAge <= 0);
	
	return retireAge;
}
double get_valid7(){     
    double annualReturn;
    int num_args_read;
    do{
		printf("Enter the annual rate of return you predict for your investments: ");
		num_args_read = scanf("%lf", &annualReturn);
	}while(!(is_valid_formatting(num_args_read, 1))||annualReturn <= 0);
	
	return annualReturn;
}
double calc_asmuch(double howmuch, double owe, double annualRate, double minLoan, double currentAge, double retireAge, double annualReturn){
    double monthRate1, monthRate2;
    double tranMonth;
    int i = 0;
    int j = 0;
    double Get;
    monthRate1 = annualRate/12;
    monthRate2 = annualReturn/12;
        do{
            owe = owe*(1+monthRate1) - howmuch;
            i++;
        }while(owe > 0 && i<= 12*(retireAge - currentAge));
        if(owe > 0){
            printf("Warning! After you retire you will still have $%.2f in loans left.", owe);
        }
        tranMonth = (howmuch + owe)*(1 + monthRate2);
        Get = tranMonth;
        do{
            Get = (Get + howmuch)*(1 + monthRate2);
        }while(j <= (12*(retireAge - currentAge) - i));
        
        return Get;
        
    }
double calc_min(double howmuch, double owe, double annualRate, double minLoan, double currentAge, double retireAge, double annualReturn){
    double monthRate1, monthRate2;
    double tranMonth;
    int i = 0;
    int j = 0;
    double Get;
    monthRate1 = annualRate/12;
    monthRate2 = annualReturn/12;
    do{
        owe = owe*(1+monthRate1) - minLoan;
        i++;
    }while(owe > 0 && i<= 12*(retireAge - currentAge));
    tranMonth = (howmuch + owe)*(1 + monthRate2);
    Get = tranMonth;
    do{
        Get = (Get + howmuch)*(1 + monthRate2);
    }while(j <= (12*(retireAge - currentAge) - i));

    return Get;
}
void input(){   
    double E, F, G, H, I, J, K;
    E = get_valid1();/*howmuch*/
    F = get_valid2();/*owe*/
    G = get_valid3();/*annualRate*/
    H = get_valid4();/*minLoan*/
    if(E < H*(1 + (G/12))){
        printf("You didn't set aside enough money to pay off our loans. Ending program.");
        exit(0);
    }
    I = get_valid5();/*currentAge*/
    J = get_valid6();/*retireAge*/
    K = get_valid7();/*annualReturn*/
    
    X = calc_asmuch(E, F, G, H, I, J, K);
    Y = calc_min(E, F, G, H, I, J, K);
    if(X > Y){
        printf("You should apply all $%.2f towards your loan before making any investments.\n", E);
        printf("If you do you will have $%.2f when you retire as opposed to $%.2f if you only made minimum payments.", X, Y);
    }
    else if(X < Y){
        printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");
        printf("If you do you will have $%.2f when you retire as opposed to $%.2f if you payed off your loan before investing.", Y, X);
    }
    

}
int main(){
    input();
    return 0;
}