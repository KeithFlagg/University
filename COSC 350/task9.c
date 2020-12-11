#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int palin(int x, int y){

  int offset; 

  if((offset = lseek (y, O_RDONLY, SEEK_END)) == -1){
    printf("lseek Error!");
    return 0;
  }

  char buffer[offset];
  read(x, buffer, offset);

  int i;

  for(i = 0; i < offset; i++){
    if(buffer[i] != buffer[(offset - 1) - i]){
      return 0;
    }
  }

  return 1;
}


int main(int argc, char **argv){

  if(argc < 2){
    printf("Not enough parameters passed, bye!\n");
    return -1;
  }

  char *infile = argv[1];
  int filedes[2];

  filedes[0] = open(infile, O_RDONLY);
  if(filedes[0] == -1){
    printf("Cannot open input file!\n");
    return -1;
  }

  filedes[1] = open(infile, O_RDONLY);
  if(filedes[1] == -1){
    printf("Cannot open input file!\n");
    return -1;
  }

  if(palin(filedes[0], filedes[1]) == 1){
    printf("This file is a palindrome!\n");
  } 
  else {
    printf("This file is not a palindrome!\n");
  }

  return 0;
}