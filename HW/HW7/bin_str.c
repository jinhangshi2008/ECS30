#include <stdio.h>
#include <string.h>
void rec_print(char* string, char* ans){
	//if the string reaches to the end, print out the string
	if(string[0] == '\0'){
		printf("%s\n", ans);
	}
	//if the character is not x, call the function again
	else if(string[0] != 'x'){
		rec_print(string + 1, ans);
	}
	else{
		//if the character is x, first set x to 0 and call the function with x = 0
		string[0] = '0';
		printf("ans:%c\n", *ans);
		rec_print(string + 1, ans);
		//then we set x = 1 and call the function again
		string[0] = '1';
		rec_print(string + 1, ans);
		//finally we return the character back to x
		string[0] = 'x';
	}
}

int main(int argc, char** argv){
	rec_print(argv[1], argv[1]);
	return 0;
}
