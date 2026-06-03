//Coordinator: The coordinator is responsible for using the 
//(1) fork() command to launch another process 
//(2) exec() command to replace the program driving this process, while also supplying the arguments that 
//this new program (Checker) needs to complete its execution. 
//(3) wait() command to wait for the completion of the execution of the process. 
//The Coordinator is responsible for launching 4 processes that it will load with the Checker program. 
//Each instance of the Checker will receive different arguments.  To facilitate this, the Coordinator will take a 
//total of five command line arguments and selectively pass them on to the Checker.  The first argument is the 
//divisor, followed by the dividends.  For instance, 
//> coordinator 3 8 15 21 45 
//Would create 4 child processes that would check 8/3, 15/3, 21/3, and 45/3, respectively. 

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    for(int i = 2; i < argc; i++){
        pid_t pid = fork();

        if(pid < 0){
            fprintf(stderr, "Fork Failed");
            return 1;
        }
        else if(pid == 0){
            printf("Child process beginning.\n");
            execlp("./checker", "checker", argv[1], argv[i], NULL);
            printf("Child process complete.\n");
        }
        else{
            printf("Parent process beginning.\n");
            int status;
            wait(&status);
            int result = WEXITSTATUS(status);
            printf("Child returned: %d\n", result);
            printf("Parent process complete.\n");
        }
    }
    
    return 0;
}