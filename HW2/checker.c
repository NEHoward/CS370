// This program requires two arguments to complete its task. The Checker checks whether or not 
//argTwo (the dividend) is divisible by argOne (the divisor) and prints out the result. Both these arguments are 
//positive integers. The two arguments that the Checker needs to perform its mathematical operation will be supplied to it by the 
//Coordinator; the Coordinator is supplied these aforementioned arguments from the command line. 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]){

    pid_t pid = getpid();

    //create integers to hold the two arguments from the coordinator || atoi() converts the string arguments to integers
    int argONE = atoi(argv[1]);
    int argTWO = atoi(argv[2]);
    
    printf("Checker process [%d]: Starting.\n", pid);
    
    // if argONE is zero, the operation is undefined. || return error message
    if(argONE == 0){
        printf("Checker process [%d]: Division by zero is undefined.\n", pid);
    }
    // if argTwo is divisible by argOne, print the result. || modulo operator == 0
     else if(argTWO % argONE == 0){
        printf("Checker process [%d]: %d *IS* divisible by %d.\n", pid, argTWO, argONE);
        printf("Checker process [%d]: Returning 1.\n", pid);
        return 1; 
    }
    // if argTwo is not divisible by argOne, print the result. || modulo operator != 0
    else{
        printf("Checker process [%d]: %d *IS NOT* divisible by %d.\n", pid, argTWO, argONE);
        printf("Checker process [%d]: Returning 0.\n", pid);
    }

    return 0;
}