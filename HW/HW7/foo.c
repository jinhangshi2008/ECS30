#include <stdio.h>
#include <stdlib.h>
//recursive function to calculate the value of n user enters
int foo(int n, int n1, int n2, int n3){
    if(n == 0){
        return n1;
    }
    else if(n == 1){
        return n2;
    }
    else if(n == 2){
        return n3;
    }
    //by calculation beforehand, we found the function foo do the calculation recursively like this pattern
    else{
        return foo(n-1, n2, n3, n1+n2+n3);
    }
}
//this function acts as the initial setting of the function foo
int foo1(int n){
    return foo(n, 2, 3, 5);
}
int main(int argc, char** argv){
    printf("foo(%d) = %d ", atoi(argv[1]), foo1(atoi(argv[1])));
    return 0;
}