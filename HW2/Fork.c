#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/wait.h>

int main(){
    pid_t pid = fork();

    if(pid < 0){
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if(pid == 0){
        printf("Child process beginning.\n");
        execlp("childTask", NULL);
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
    return 0;
}