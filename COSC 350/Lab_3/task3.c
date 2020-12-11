//COSC 350
//Keith Flagg

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

	char *input = "foo", *output = "clone2";
	//creates file descriptors
	int filedes[2];

	//creates a read only file
	filedes[0] = open(input, O_RDONLY);
	if (filedes[0] == -1){
		printf("File cannot be opened!\n");
		return 0;
	}

	//set permissions
	umask(0);
	//creates rwxrwx---
	filedes[1] = open(output, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP);

	printf("Opened files: %d, %d\n", filedes[0], filedes[1]);

	//read 32 bytes at a time 
	char buf[32];

	while ((read(filedes[0], buf, 32) > 0)){
		//writes to clone file
		write(filedes[1], buf, 32);
	}
	//closes the files
	close(filedes[0]);
	close(filedes[1]);

	return 0;

}
