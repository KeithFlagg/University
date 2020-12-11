//COSC 350
//Keith Flagg

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int stringtoint(char *c){
  //converts a string to an int
  int i = 0;
  long int num = 0;
  while(c[i] != '\0'){
    num = 10 * num + (c[i] - '0');
    i++;
  }

  return num;
}

int main(int argc, char* argv[])
{
    int nc = stringtoint(argv[1]), np = stringtoint(argv[2]), tc = stringtoint(argv[3]), tp = stringtoint(argv[4]);

    pid_t pid;
    char* message;
    int n, t, exit_code;

    if(argc < 4){
    printf("Please Type: ./forkWait [nc] [np] [tc] [tp]\n");
    return 0;
    }

    printf("Fork program starting.\n");
    pid = fork();

    switch(pid){
        case -1:
            perror("Fork failed.");
            exit(1);
        case 0:
            message = "This is the child.";
            n = nc;
            t = tc;
            exit_code = 37;
            break;
        default:
            message = "This is the parent.";
            n = np;
            t = tp;
            exit_code = 0;
            wait(&pid);
            break;
    }

    for(; n > 0; n--){
        puts(message);
        sleep(t);
    }

    /*
    The program waits by checking the pid of the process. 
    The parent process must wait on the child
    In the case ./forkWait 5 3 1 1 The child prints 5 times,
    then the parent prints 5 times. There is no messy output.
    */

    if(pid != 0){
        int stat_val;
        pid_t child_pid;

        child_pid = wait(&stat_val);

        printf("Child  has finished: PID = %d. \n", child_pid);

        if(WIFEXITED(stat_val)){
            printf("Child exited with code %d. \n", WEXITSTATUS(stat_val));
        }
        else{
            printf("Child terminated abnormally. \n");
        }
    }

    exit(exit_code);
}
