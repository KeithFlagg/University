//Keith Flagg
//COSC 350

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int data_processed, data2;
    int file_pipes[2];
    int pipe2[2];
    const char some_data[] = "Hi there, Kiddo";
    char buffer[BUFSIZ + 1];
    pid_t fork_result;

    memset(buffer, '\0', sizeof(buffer));

    if(pipe(file_pipes) == 0 && pipe(pipe2) == 0){
        fork_result = fork();
    	if(fork_result == -1){
        	fprintf(stderr, "Fork Failed");
        	exit(EXIT_FAILURE);
    	}

    	if(fork_result==0){
            // Send the message "Hi there, Kiddo" and file descriptors to the child 
            char rBuffer[BUFSIZ + 1];
            char wBuffer[BUFSIZ + 1];
            close(file_pipes[1]);
            close(pipe2[0]);
            sprintf(rBuffer, "%d", file_pipes[0]);
            sprintf(wBuffer, "%d", pipe2[1]);
            //execute files
       		(void)execl("twoPipesChild", "twoPipesChild", rBuffer, wBuffer, (char*)0);
    	    exit(EXIT_FAILURE);
    	}
    	else{//print message
            close(file_pipes[0]);
            close(pipe2[1]);
        	data_processed=write(file_pipes[1], some_data, strlen(some_data));
            data2 = read(pipe2[0], buffer, 6);
            printf("Parent (%d) sent %d bytes to the child. \n", getpid(), 15);
        	wait(&fork_result);
        	printf("Parent (%d) recieved the message \" %s \" Byte count: %d\n", getpid(), buffer, data2);
    	}
  	}
    exit(EXIT_SUCCESS);
}