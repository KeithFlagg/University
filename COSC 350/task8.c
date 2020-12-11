#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

void inttostring(int ascii, char *buffer, int x){
	int i;
	//zero in ascii
	int zero = 48;

	for(i = (x-1); i >= 0; i--){

    buffer[i] = ascii % 10 + zero;

    ascii /= 10;
  }
}

int main(int argc, char **argv){

  if(argc < 3){
    printf("Not enough parameters passed, bye!\n");
    return -1;
  }

  char *input = argv[1];
  char *output = argv[2];
  int filedes[2];

  filedes[0] = open(input, O_RDONLY);

  if(filedes[0] == -1){
    printf("Cannot open the file!\n");
    return -1;
  }

  //get permissions
  umask(0);

  filedes[1] = open(output, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH, S_IWOTH);

  char buffer[1];
  int ascii;
  int nread;

  while ((nread = read(filedes[0], buffer, 1) > 0)){

    ascii = (int)buffer[0];
    
    char *str; //need 3 chars

    if(ascii > 100){
      str = malloc(3);
      inttostring(ascii, str, 3);
    } 
    else {
      str = malloc(2);
      inttostring(ascii, str, 2);
    }

    write(filedes[1], str, sizeof(str));
  }

  close(filedes[0]);
  close(filedes[1]);
  close(filedes[2]);

  return 0;
}