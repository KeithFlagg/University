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
	int nc = stringtoint(argv[1]);
	int np = stringtoint(argv[2]);
	int tc = stringtoint(argv[3]);
	int tp = stringtoint(argv[4]);

	pid_t pid;
	int n, t, exit_code;

	if(argc < 4){
    printf("Please Type: ./forkExec [nc] [np] [tc] [tp]\n");
    return 0;
    }

	printf("Fork program starting.\n");
	pid = fork();

	switch(pid){
		case -1:
			perror("Fork failed.");
			exit(1);
		case 0:
			execlp("./child", argv[1], argv[3], "Child.", (char *)0);
			break;
		default:
	
			for(; np > 0; np--){
				printf("PID = %d. \n", getpid());
				sleep(tp);
			}
			break;
	}

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