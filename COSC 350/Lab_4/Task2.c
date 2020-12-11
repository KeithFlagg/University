//COSC 350
//Keith Flagg

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int isNum(char c){
	//determine if charater is in range 0-9

	int asciiZero = (int)'0';
	int asciiNine = (int)'9';

	//stores the pased ascii char as int
	int ascii = (int)c;

	if(ascii >= asciiZero && ascii <= asciiNine){
		return ascii;
	}
	return 0;
}

int stringtoint(char *c){
  int i = 0, num = 0;
  while(c[i] != '\0'){
    num = (10 * num) + (c[i] - 48);
    i++;
  }
  return num;
}

void asciichar(int fd, char ascii[]){

  int asciival = stringtoint(ascii);
  char c = asciival; 
  write(fd, &c, 1); 
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
  //3 for Ascii and extra '\0'
  char currChar[4];
  int curr = 0;

  
  while((read(filedes[0], buffer, 1) > 0)){
	if((buffer[0] == ' ' || buffer[0] == '\n')){
		currChar[curr] = '\0';
		asciichar(filedes[1], currChar);
		curr = 0;
    }
    else if (isNum(buffer[0])){
    	currChar[curr] = buffer[0];
    	curr++;
    }
  }


  	close(filedes[0]);
  	close(filedes[1]);
  	close(filedes[2]);

  return 0;
}
