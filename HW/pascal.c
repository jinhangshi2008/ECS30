#include <stdio.h>
/*This program is to present a Pascal's triangle, given the number of level.*/
void formula(int numLevel){
    int i, j, x;
    /*The number of the level directly decides the number of integer on that level.
    By using the first for loop, we decide the calculations to be done by how many times.*/
    for (i = 0; i < numLevel; i++){
      /*The second for loop calculates each integers on one level.*/
      for (j = 0 ; j <= i; j++){
          if(i == 0 || j == 0){
              x = 1;
          }
          else{
              x = x*(i-j+1)/j;
          }
         printf("%d ", x);
   }
   /*In the end of each level, start a new line.*/
   printf("\n");
}
}
int main(){
    int numLevel;
    printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
    scanf("%d", &numLevel);
    formula(numLevel);
    return 0;
}