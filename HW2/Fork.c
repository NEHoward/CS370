#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/wait.h>

int main(){
    //fork code from video lecture.

    pid_t pid = fork();

    if(pid < 0){
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if(pid == 0){
        execlp("childTask", NULL);
        printf("Child process complete.\n");
    }
    else{
        printf("Parent process beginning.\n");
        int status;
        printf("Coordinator: waiting for process [%d].\n", pid);
        wait(&status);
        int result = WEXITSTATUS(status);
        printf("Coordinator: child process [%d] returned %d.\n", pid, result);
    }
    printf("Coordinator: exiting.\n");
    return 0;
}