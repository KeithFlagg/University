//COSC 350
//Keith Flagg

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

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

int main(int argc, char **argv){

  pid_t pid;
  char *message;
  int n;

  if(argc < 4){
    printf("Please Type: ./fork1 [nc] [np] [tc] [tp]\n");
    return 0;
  }

  int nc = stringtoint(argv[1]), np = stringtoint(argv[2]), tc = stringtoint(argv[3]), tp = stringtoint(argv[4]);

  printf("fork program starting\n");
  pid = fork();

  int sp;

  switch (pid) {
    case -1:
      printf("fork failed");
    break;
    case 0:
      message = "This is the child";
      n = nc;
      sp = tc;
    break;
    default:
      message = "This is the parent";
      n = np;
      sp = tp;
    break;
  }

  for(; n > 0; n--){
    puts(message);
    sleep(sp);
  }

  return 0;

}
