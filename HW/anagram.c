#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*This program is to check whether two words are anagrams or not.*/
/*If the string lengths of two words are different, they are not anagrams.*/
bool check_word(char* first_word, char* second_word){
    return strlen(first_word) == strlen(second_word);
}
void check(char* first_word, char* second_word){
  if(!(check_word(first_word, second_word))){
    printf("%s is NOT an anagram of %s", first_word, second_word);
    exit(0);
  }
}
void result(char* first_word, char* second_word){
   int i;
   int j;
   int x;
   int y = 0;
   /*These two for loops aims to compare each letter of the first word to each one of the second word.*/
   for(i=0;i<strlen(first_word);i++){
       if(first_word[i] == first_word[i + 1]){
           printf("%s is NOT an anagram of %s", first_word, second_word);
           exit(0);
       }
        for(j=0;j<strlen(first_word);j++){
                x = first_word[i] - second_word[j];
                if(x == 32||x == -32||x == 0){
                    y++;
                    break;/*This prevents the program to match the same letter repeatedly*/
                }
            }
    }
/*By counting the number of successful matches(y) and comparing with the length of the string,
 decide whether they are anagram or not.*/
if(y != strlen(first_word)){
  printf("%s is NOT an anagram of %s", first_word, second_word);
}
else if(y == strlen(first_word)){
  printf("%s is an anagram of %s", first_word, second_word);
}
}
int main(){
char first[20], second[20];
    printf("Please enter the first word: ");
    scanf("%s", first);
    printf("Please enter the second word: ");
    scanf(" %s", second);
    check(first, second);
    result(first, second);
  return 0;
}