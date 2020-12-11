//COSC 350
//Keith Flagg

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

	char *input = "foo", *output = "clone";
	//create the file descriptors
	int filedes[2];

	//creates read only file
	filedes[0] = open(input, O_RDONLY);
	if (filedes[0] == -1){
		printf("File cannot be opened!\n");
		return 0;
	}

	//set permissions
	umask(0);
	//creates rw-rw-rw-
	filedes[1] = open(output, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IWGRP | S_IROTH | S_IWOTH);

	printf("Opened files: %d, %d\n", filedes[0], filedes[1]);

	//read one byte at a time 
	char buf[1];
	int nread;

	while ((nread = read(filedes[0], buf, 1) > 0)){
		//writes to clone file
		write(filedes[1], buf, nread);
	}
	//closes the files
	close(filedes[0]);
	close(filedes[1]);

	return 0;

}
