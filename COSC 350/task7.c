#include <stdio.h>
#include <stdlib.h>

int stringtoint(char *c){

  //converts a string to an int

  int i = 0;
  int num = 0;

  while(c[i] != '\0'){
    num = (10 * num) + (c[i] - '0');
    i++;
  }

  return num;
}

int main(int argc, char **argv){

  if(argc < 2){
    printf("You must have an argument passed, bye!\n");
    return 0;
  }

  int i, sum = 0;
  for(i = 1; i < argc; i++){
    sum += stringtoint(argv[i]);
  }

  printf("Sum: %d\n", sum);

 return 0;

}