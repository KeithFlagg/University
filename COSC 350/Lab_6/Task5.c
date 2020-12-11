//COSC 350
//Keith Flagg

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int isdigit(int n)
{
    if(n >= 48 && n <= 57)
        return 1;
    else
        return 0;
}

int main(int argc, char* argv[])
{
    pid_t pid;
    int infile, childOut, parentOut, exit_code;
    char buf;
    int cOffset = 0;
    int pOffset = 0;

    infile = open(argv[1], O_RDONLY);

    if(infile < 0){
        puts("No input file! Please Type: ./Task5 [inputfile]");
		exit(1);
    }

    parentOut = open("parent.txt", O_WRONLY|O_CREAT|O_EXCL, 0755);
    childOut = open("child.txt", O_WRONLY|O_CREAT|O_EXCL, 0755);

    if(childOut < 0 || parentOut < 0)
    {
        puts("No output file!");
		exit(1);
    }

    pid = fork();

        switch(pid){
            case -1:
                perror("Fork failed");
                exit(1);
            case 0:
                exit_code = 37;
                while(pread(infile, &buf, 1, cOffset) == 1){
                if(isdigit(buf) == 0)
                {
                    write(childOut, &buf, 1);
                }
                cOffset++;
            }
                break;
            default:
                exit_code = 0;
                while(pread(infile, &buf, 1, pOffset) == 1){
                if(isdigit(buf) == 1){
                    write(parentOut, &buf, 1);
                }
                pOffset++;
            }
                break;
        }

    close(infile);
    close(childOut);
    close(parentOut);

    if(pid != 0)
    {
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
