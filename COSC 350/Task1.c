//COSC 350
//Keith Flagg

#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int convIntToStr(char *str, int x){
	sprintf(str,"%d", x);
	return (strlen(str));
}

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

  //converts string to int without atoi

  int i = 0;
  long int num = 0;

  while(c[i] != '\0'){
    num = 10 * num + (c[i] - '0');
    i++;
  }

  return num;

}

int main(int argc, char **argv){

  if(argc < 2){
    printf("You must pass more arguments!\n");
    return 0;
  }

  int filedes;
  char *input = argv[1];

  //opens as read only
  filedes = open(argv[1], O_RDONLY);

  if(filedes == -1){
    printf("Cannot open the input file!\n");
    return 0;
  }

  //creates the buffer to hold a one byte char
  char buffer[1];
  //max buffer
  char str[80];
  int nread;
  int i = 0;


  while ((nread = read(filedes, buffer, 1) > 0)){

    //makes sure ascii is a num
    if(isNum(buffer[0])){

      str[i] = buffer[0];
      i++;
    }
  }

  printf("Input Number: %s\n", str);

  long int output = stringtoint(str);

  output += 10;

  char intarr[i];

  convIntToStr(intarr, output);

  printf("Input Number +10: %s\n", intarr);

  close(filedes);

  return 0;

}