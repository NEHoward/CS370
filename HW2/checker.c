// This program requires two arguments to complete its task. The Checker checks whether or not 
//argTwo (the dividend) is divisible by argOne (the divisor) and prints out the result. Both these arguments are 
//positive integers. The two arguments that the Checker needs to perform its mathematical operation will be supplied to it by the 
//Coordinator; the Coordinator is supplied these aforementioned arguments from the command line. 

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    //create integers to hold the two arguments from the coordinator || atoi() converts the string arguments to integers
    int argONE = atoi(argv[1]);
    int argTWO = atoi(argv[2]);

    // if argONE is zero, the operation is undefined. || return error message
    if(argONE == 0){
        printf("Error: Division by zero is undefined.\n");
    }
    // if argTwo is divisible by argOne, print the result. || modulo operator == 0
     else if(argTWO % argONE == 0){
        printf("%d is divisible by %d.\n", argTWO, argONE); 
    }
    // if argTwo is not divisible by argOne, print the result. || modulo operator != 0
    else{
        printf("%d is not divisible by %d.\n", argTWO, argONE); 
    }

    return 0;
}